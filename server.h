#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <chrono>
#include <netinet/in.h>
#include <thread>
#include <iostream>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <arpa/inet.h>

#include "player.h"



struct Info
{
  Info(std::vector<double> t, Player* player)
  {
      times = t;
      this->player = player;
  }
  ~Info();
  std::vector<double> times;
  Player* player;
};

class Server
{
private:
    int serverSocket;
    struct sockaddr_in addr;
    std::vector<pthread_t> threads;
    std::vector<double> timeOfPlayers;
    std::vector<Player*> players;
    size_t numbOfPlayers;
public:
    Server(size_t numbOfPlayers);
    void doServer();
    static void *threadFunc(void* arg);
};

#endif // SERVER_H
