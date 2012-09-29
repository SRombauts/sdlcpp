#include "Rect.h"

Rect::Rect(const int aX, const int aY, const unsigned int aW, const unsigned int aH)
{
    mRect.x = (Sint16)aX;
    mRect.y = (Sint16)aY;
    mRect.w = (Uint16)aW;
    mRect.h = (Uint16)aH;
    mX2 = (int)(aX + aW - 1);
    mY2 = (int)(aY + aH - 1);
}

Rect::~Rect(void)
{
}

