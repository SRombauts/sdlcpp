#include "Position.h"


Position::Position(const int aX /* = 0 */, const int aY /* = 0 */)
{
    mRect.x = (Sint16)aX;
    mRect.y = (Sint16)aY;
    mRect.w = 0;
    mRect.h = 0;
}

Position::~Position(void)
{
}

void Position::set(const int aX /* = 0 */, const int aY /* = 0 */)
{
    mRect.x = (Sint16)aX;
    mRect.y = (Sint16)aY;
}

void Position::incr(const int aIncrX /* = 0 */, const int aIncrY /* = 0 */)
{
    mRect.x = (Sint16)(mRect.x + aIncrX);
    mRect.y = (Sint16)(mRect.y + aIncrY);
}
