#include <iostream>
#include "Image.h"
#include "Screen.h"

Image::Image (const char* apFileName) :
    mpSurface(NULL),
    mbValid(false)
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
           mbValid = true;
       }
       else
       {
          std::cout << "Optimize error: %s\n" << SDL_GetError() << std::endl;
       }
       // Libération de l'image non optimisée
       SDL_FreeSurface(pSurfaceUnoptimized);
    }
    else
    {
       std::cout << "Load error: %s\n" << SDL_GetError() << std::endl;
    }
}
