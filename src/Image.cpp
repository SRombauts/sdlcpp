#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Image.h"
#include "Screen.h"

/// Constructeur RAII (exception en cas d'erreur : l'objet est toujours valide)
Image::Image(const char* apFileName, const Sint16 aX /* = 0 */, const Sint16 aY /* = 0 */) :
    Surface(aX, aY)
{
    SDL_Surface* pSurfaceUnoptimized = NULL; // Surface tampon pour charger l'image non optimisé

    // Chargement de l'image
    pSurfaceUnoptimized = SDL_LoadBMP(apFileName);
    // Si le chargement s'est bien passé
    if (NULL != pSurfaceUnoptimized)
    {
       // Création de l'image optimisée
       mpSurface = SDL_DisplayFormat(pSurfaceUnoptimized);
       if (NULL != mpSurface)
       {
           // Libération de l'image non optimisée
           SDL_FreeSurface(pSurfaceUnoptimized);
       }
       else
       {
          std::cout << "Image: Optimize error: %s\n" << SDL_GetError() << std::endl;
          std::ostringstream streamErr;
          streamErr << "Image: Load error: " << SDL_GetError();
          throw std::runtime_error(streamErr.str());
       }
    }
    else
    {
        std::ostringstream streamErr;
        streamErr << "Image: Load error: " << SDL_GetError();
        throw std::runtime_error(streamErr.str());
    }
}

/// Destructeur : libération des ressources
Image::~Image(void)
{
    // Tout est fait dans le destructeur Surface::~Surface() de la classe mère
}
