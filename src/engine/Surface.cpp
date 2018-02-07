#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Surface.h"
#include "Sprite.h"
#include "Coord.h"


Surface::Surface(void) :
    mpSurface(nullptr)
{
}

/// Destructeur : libération des ressources
Surface::~Surface(void)
{
    if (nullptr != mpSurface)
    {
        SDL_FreeSurface(mpSurface);
    }
}

/// Blit la Surface passée en argument sur la surface courante (sans offset)
bool Surface::blit(Surface& aSurface)
{
    bool bRet = (0 == SDL_BlitSurface(aSurface.mpSurface, nullptr, mpSurface, nullptr));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}

/// Blit la Surface passée en argument (avec son offset) sur la surface courante
bool Surface::blit(Surface& aSurface, Coord& aOffset)
{
    bool bRet = (0 == SDL_BlitSurface(aSurface.mpSurface, nullptr, mpSurface, &aOffset.getRect()));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}

/// Blit le Sprite passée en argument (avec son offset) sur la surface courante
bool Surface::blit(Sprite& aSprite, Coord& aOffset)
{
    bool bRet = (0 == SDL_BlitSurface(&aSprite.getSurface().getSurface(), &aSprite.getRect().getRect(), mpSurface, &aOffset.getRect()));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}
