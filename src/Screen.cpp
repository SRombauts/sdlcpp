#include <iostream>
#include "Screen.h"
#include "Image.h"

// Les paramètres de notre écran
const int SCREEN_BPP    = 32;

Screen::Screen (const int aWidth, const int aHeight, const char* apTitle) :
    mpSurface(NULL),
    mbValid(false)
{
    // Initialisation de la fenêtre principale
    mpSurface = SDL_SetVideoMode(aWidth, aHeight, SCREEN_BPP, SDL_HWSURFACE);
    if (NULL != mpSurface)
    {
        // Mise en place de sa barre de titre
        SDL_WM_SetCaption(apTitle, NULL);
        mbValid = true;
    }
    else
    {
        std::cout << "Can't set video mode: " << SDL_GetError() << std::endl;
    }
}

/// Blitte la surface sur l'écran
bool Screen::blit(SDL_Surface* apSurface)
{
    bool bRet = (0 == SDL_BlitSurface(apSurface, NULL, mpSurface, NULL));
    if (false == bRet)
    {
       std::cout << "Blit error: %s\n" << SDL_GetError() << std::endl;
    }
    return bRet;
}

/// Blitte l'image sur l'écran
bool Screen::blit(Image& aImage)
{
    bool bRet = (0 == SDL_BlitSurface(aImage.mpSurface, NULL, mpSurface, NULL));
    if (false == bRet)
    {
       std::cout << "Blit error: %s\n" << SDL_GetError() << std::endl;
    }
    return bRet;
}

/// Mise à jour de l'écran
bool Screen::flip(void)
{
    bool bRet = (0 == SDL_Flip(mpSurface));
    if (false == bRet)
    {
       std::cout << "Flip error: %s\n" << SDL_GetError() << std::endl;
    }
    return bRet;
}
