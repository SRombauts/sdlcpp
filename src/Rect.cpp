#include "Rect.h"

Rect::Rect(const Sint16 aX, const Sint16 aY, const Uint16 aW, const Uint16 aH)
{
    mRect.x = aX;
    mRect.y = aY;
    mRect.w = aW;
    mRect.h = aH;
    mX2 = (Sint16)(aX + aW);
    mY2 = (Sint16)(aY + aH);
}

Rect::~Rect(void)
{
}

