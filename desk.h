#ifndef DESK_H
#define DESK_H
#include<stdio.h>

class Desk
{
public:
    Desk();
    bool targets[5] = {false, false, false, false, false};
    void close_target(size_t I);
};

#endif // DESK_H
