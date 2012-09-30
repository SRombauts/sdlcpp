#include "Offset.h"


Offset::Offset(const int aX /* = 0 */, const int aY /* = 0 */) :
    mX(aX),
    mY(aY)
{
}

Offset::~Offset(void)
{
}

void Offset::set(const int aX /* = 0 */, const int aY /* = 0 */)
{
    mX = aX;
    mY = aY;
}

void Offset::incr(const int aIncrX /* = 0 */, const int aIncrY /* = 0 */)
{
    mX = mX + aIncrX;
    mY = mY + aIncrY;
}
