#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Position.h"

Position::Position(const Sint16 aX /* = 0 */, const Sint16 aY /* = 0 */)
{
    mRect.x = aX;
    mRect.y = aY;
    mRect.w = 0;
    mRect.h = 0;
}

Position::~Position(void)
{
}


/// Met à jour l'offset de la surface courante
void Position::set(const Sint16 aX /* = 0 */, const Sint16 aY /* = 0 */)
{
    mRect.x = aX;
    mRect.y = aY;
}

void Position::incr(const Sint16 aIncrX /* = 0 */, const Sint16 aIncrY /* = 0 */)
{
    mRect.x = (Sint16)(mRect.x + aIncrX);
    mRect.y = (Sint16)(mRect.y + aIncrY);
}

