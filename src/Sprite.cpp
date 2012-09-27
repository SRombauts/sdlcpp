#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Sprite.h"
#include "Surface.h"


Sprite::Sprite(Surface& aSurface, const Sint16 aX, const Sint16 aY, const Uint16 aW, const Uint16 aH) :
    mSurface(aSurface),
    mRect(aX, aY, aW, aH)
{
}

Sprite::~Sprite(void)
{
}
