#include "Position.h"


Position::Position(const int aX /* = 0 */, const int aY /* = 0 */) :
    mX(aX),
    mY(aY)
{
}

Position::~Position(void)
{
}

void Position::set(const int aX /* = 0 */, const int aY /* = 0 */)
{
    mX = aX;
    mY = aY;
}

void Position::incr(const int aIncrX /* = 0 */, const int aIncrY /* = 0 */)
{
    mX = mX + aIncrX;
    mY = mY + aIncrY;
}
