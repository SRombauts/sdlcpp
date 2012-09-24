#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Surface.h"

/// Constructeur RAII (exception en cas d'erreur : l'objet est toujours valide)
Surface::Surface(const Sint16 aX /* = 0 */, const Sint16 aY /* = 0 */) :
    mpSurface(NULL)
{
    mOffset.x = aX;
    mOffset.y = aY;
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
    bool bRet = (0 == SDL_BlitSurface(aSurface.mpSurface, NULL, mpSurface, &aSurface.mOffset));
    if (false == bRet)
    {
       std::cout << "Blit error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}

/// Met à jour l'offset de la surface courante
void Surface::set(const Sint16 aX /* = 0 */, const Sint16 aY /* = 0 */)
{
    mOffset.x = aX;
    mOffset.y = aY;
}
