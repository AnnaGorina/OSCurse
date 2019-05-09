#include "server.h"

Server::Server(size_t numbOfPlayers)
{
    this->numbOfPlayers = numbOfPlayers;
    threads.resize(numbOfPlayers);
    timeOfPlayers.resize(numbOfPlayers);
    for(size_t i = 0; i < numbOfPlayers; i++)
    {
        timeOfPlayers[i] = -1;
    }
    players.resize(numbOfPlayers);

    serverSocket = socket(AF_INET,SOCK_STREAM,0);
    if(serverSocket < 0)
    {
        perror("Bad socket: ");
        exit(0);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(2048);
    addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(serverSocket,(struct sockaddr*)&addr,sizeof(addr)) < 0)
    {
        perror("Bad bind ");
        exit(0);
    }
    listen(serverSocket, 10);
}

void Server::doServer()
{
    for(size_t i = 0; i < numbOfPlayers; i++)
    {
        int accepted = accept(serverSocket,0,0);
        players[i] = new Player(accepted,i);
        send(players[i]->socket,&players[i]->ID,sizeof(int),0);
        Info* tmp = new Info(timeOfPlayers,players[i]);
        pthread_create(&threads[i],0,threadFunc,static_cast<void*>(tmp));
    }
    for(size_t i = 0; i < numbOfPlayers; i++)
    {
        pthread_join(threads[i],NULL);
    }
    return;
}

void *Server::threadFunc(void *arg)
{
    bool goal = true;
    bool not_goal = false;
    Info* info = static_cast<Info*>(arg);

    std::chrono::time_point<std::chrono::system_clock> timer;
    std::chrono::time_point<std::chrono::system_clock> end;

    timer = std::chrono::system_clock::now();

    for(size_t i = 0; i < 5; i++)
    {
        recv(info->player->socket,&info->player->aim.x,sizeof(double),0);
        recv(info->player->socket,&info->player->aim.y,sizeof(double),0);
        if(info->player->registretion())
        {
            send(info->player->socket,&goal,sizeof(bool),0);
        }
        else
        {
            send(info->player->socket,&not_goal,sizeof(bool),0);
        }
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> tmp = timer - end;
    info->player->time += tmp.count() / 1000;
    info->times[info->player->ID] = info->player->time;
    recv(info->player->socket,(void*)&info->times,sizeof(info->times),0);
    pthread_exit(0);
}
