#include "player.h"

Player::Player(int socket, size_t id)
{
    ID = id;
    time = 0;
    I = 0;
    this->socket = socket;
}

bool Player::registretion()
{
    if (aim.shoot())
    {
        desk.close_target(I);
        I ++;
        //aim.replace();
        return true;
    }
    else
    {
        //штрафное время t += n;
        I ++;
        //aim.replace();
        return false;
    }

}
