#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Surface.h"
#include "Sprite.h"
#include "Position.h"


Surface::Surface(void) :
    mpSurface(NULL)
{
}

/// Destructeur : libération des ressources
Surface::~Surface(void)
{
    if (NULL != mpSurface)
    {
        SDL_FreeSurface(mpSurface);
    }
}

/// Blit la Surface passée en argument sur la surface courante (sans offset)
bool Surface::blit(Surface& aSurface)
{
    bool bRet = (0 == SDL_BlitSurface(aSurface.mpSurface, NULL, mpSurface, NULL));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}

/// Blit la Surface passée en argument (avec son offset) sur la surface courante
bool Surface::blit(Surface& aSurface, Position& aOffset)
{
    bool bRet = (0 == SDL_BlitSurface(aSurface.mpSurface, NULL, mpSurface, &aOffset.getRect()));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}

/// Blit le Sprite passée en argument (avec son offset) sur la surface courante
bool Surface::blit(Sprite& aSprite, Position& aOffset)
{
    bool bRet = (0 == SDL_BlitSurface(&aSprite.getSurface().getSurface(), &aSprite.getRect().getRect(), mpSurface, &aOffset.getRect()));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}
