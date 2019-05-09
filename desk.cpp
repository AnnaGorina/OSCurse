#include "desk.h"

Desk::Desk()
{
    
}

void Desk::close_target(size_t I)
{
    targets[I] = true;
}
