#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Image.h"
#include "Screen.h"

/// Constructeur RAII (exception en cas d'erreur : l'objet est toujours valide)
Image::Image(const char* apFileName, const Sint16 aX /* = 0 */, const Sint16 aY /* = 0 */) :
    Surface(aX, aY)
{
    // Chargement de l'image
    mpSurface = SDL_LoadBMP(apFileName);
    // Si le chargement se passe bien
    if (NULL != mpSurface)
    {
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
}
