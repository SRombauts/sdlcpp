#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Surface.h"
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

/// Blitte la surface passée en argument (avec son offset) sur la surface courante
bool Surface::blit(Surface& aSurface)
{
    bool bRet = (0 == SDL_BlitSurface(aSurface.mpSurface, NULL, mpSurface, NULL));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}

/// Blitte la surface passée en argument (avec son offset) sur la surface courante
bool Surface::blit(Surface& aSurface, Position& aOffset)
{
    bool bRet = (0 == SDL_BlitSurface(aSurface.mpSurface, NULL, mpSurface, &aOffset.getRect()));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}
