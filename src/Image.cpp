#include <iostream>
#include "Image.h"
#include "Screen.h"

Image::Image (const char* apFileName) :
    mpSurface(NULL),
    mbValid(false)
{
    // Chargement de l'image
    mpSurface = SDL_LoadBMP(apFileName);
    // Si le chargement se passe bien
    if (NULL != mpSurface)
    {
        mbValid = true;
    }
    else
    {
       std::cout << "Load error: %s\n" << SDL_GetError() << std::endl;
    }
}
