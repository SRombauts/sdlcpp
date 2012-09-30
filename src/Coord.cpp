#include "Coord.h"


Coord::Coord(const int aX /* = 0 */, const int aY /* = 0 */)
{
    mRect.x = (Sint16)aX;
    mRect.y = (Sint16)aY;
    mRect.w = 0;
    mRect.h = 0;
}

Coord::~Coord(void)
{
}

void Coord::set(const int aX, const int aY)
{
    mRect.x = (Sint16)aX;
    mRect.y = (Sint16)aY;
}

void Coord::incr(const int aIncrX, const int aIncrY)
{
    mRect.x = (Sint16)(mRect.x + aIncrX);
    mRect.y = (Sint16)(mRect.y + aIncrY);
}
