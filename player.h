#ifndef PLAYER_H
#define PLAYER_H
#include "aim.h"
#include "desk.h"
#include <stdio.h>

class Player
{
private:

    Desk desk;
    size_t I;
public:
    Aim aim;
    size_t ID;
    Player(int socket,size_t id);
    bool registretion();
    int socket;
    double time;
};

#endif // PLAYER_H
