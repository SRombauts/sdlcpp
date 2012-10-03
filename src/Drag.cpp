#include <stdexcept>
#include <iostream>

#include "Drag.h"
#include "Screen.h"

/// RAII : garantie qu'un élément d'Drag est toujours valide (dispose au moins d'un Sprite)
Drag::Drag(const Sprite::Ptr&   aSpritePtr) :
    mSpritePtr(aSpritePtr),
    mbIsVisible(false)
{
    if (!aSpritePtr)
    {
        throw std::runtime_error("Drag::Drag: aSpritePtr NULL");
    }
}

Drag::~Drag(void)
{
}

void Drag::show(Screen& aScreen)
{
    if (mbIsVisible)
    {
        aScreen.blit(*mSpritePtr, mCoord);
    }
}
