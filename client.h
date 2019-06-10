#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <chrono>
#include <thread>
#include <fcntl.h>


class client
{
private:
    struct sockaddr_in addr;
    int clientSocket;
public:
    bool JoinClient(char *address);
    void CloseClient();
    void setClient(char dir);
    bool Coordinates();
    client();
};

#endif // CLIENT_H
