#include "Offset.h"

Offset::Offset(const int aX /* = 0 */, const int aY /* = 0 */) :
    mX(aX),
    mY(aY)
{
}

Offset::~Offset(void)
{
}

void Offset::set(const int aX, const int aY)
{
    mX = aX;
    mY = aY;
}

void Offset::incr(const int aIncrX, const int aIncrY)
{
    mX = mX + aIncrX;
    mY = mY + aIncrY;
}
