#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Surface.h"

/// Constructeur RAII (exception en cas d'erreur : l'objet est toujours valide)
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

bool Surface::blit(Surface& aSurface)
{
    bool bRet = (0 == SDL_BlitSurface(aSurface.mpSurface, NULL, mpSurface, NULL));
    if (false == bRet)
    {
       std::cout << "Blit error: %s\n" << SDL_GetError() << std::endl;
    }
    return bRet;
}
