#include "Position.h"

Position::Position(const int aX /* = 0 */, const int aY /* = 0 */) :
    mX(aX),
    mY(aY)
{
}

Position::~Position(void)
{
}

void Position::set(const int aX, const int aY)
{
    mX = aX;
    mY = aY;
}

void Position::incr(const int aIncrX, const int aIncrY)
{
    mX = mX + aIncrX;
    mY = mY + aIncrY;
}
