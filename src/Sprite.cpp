#include "Sprite.h"
#include "Surface.h"


Sprite::Sprite(const Surface::Ptr&  aSurfacePtr,
               const int            aX,
               const int            aY,
               const unsigned int   aW,
               const unsigned int   aH) :
    mSurfacePtr(aSurfacePtr),
    mRect(aX, aY, aW, aH)
{
}

Sprite::~Sprite(void)
{
}
