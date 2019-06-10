#include "client.h"

client::client()
{

}

bool client::JoinClient(char* address)
{
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2048);
    addr.sin_addr.s_addr = inet_addr(address);

    connect(clientSocket, (struct sockaddr*)&addr, sizeof(addr));

    return true;
}

void client::CloseClient()
{
    close(clientSocket);
}

void client::setClient(char dir)
{
    send(clientSocket, &dir, sizeof(char), 0);
}

bool client::Coordinates()
{
    if()
    {
        recv(clientSocket, &Coord, sizeof(Coord), 0);
        return true;
    }

    else return false;
}
