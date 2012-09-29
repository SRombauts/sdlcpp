#include "Zone.h"

Zone::Zone(const unsigned int aX,
           const unsigned int aY,
           const unsigned int aW,
           const unsigned int aH) :
   mX(aX),
   mY(aY),
   mX2(aX + aW),
   mY2(aY + aH)
{
}

Zone::~Zone(void)
{
}

