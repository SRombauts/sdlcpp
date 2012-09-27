#include "Sprite.h"
#include "Surface.h"


Sprite::Sprite(Surface::Ptr& aSurfacePtr, const Sint16 aX, const Sint16 aY, const Uint16 aW, const Uint16 aH) :
    mSurfacePtr(aSurfacePtr),
    mRect(aX, aY, aW, aH)
{
}

Sprite::~Sprite(void)
{
}
