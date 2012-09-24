#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Screen.h"
#include "Image.h"

/// Les paramètres de notre écran
const int SCREEN_BPP    = 32;

/// Constructeur RAII (exception en cas d'erreur : l'objet est toujours valide)
Screen::Screen (const int aWidth, const int aHeight, const char* apTitle) :
    mpSurface(NULL)
{
    // Initialisation de la fenêtre principale
    mpSurface = SDL_SetVideoMode(aWidth, aHeight, SCREEN_BPP, SDL_HWSURFACE);
    if (NULL != mpSurface)
    {
        // Mise en place de sa barre de titre
        SDL_WM_SetCaption(apTitle, NULL);
    }
    else
    {
        std::ostringstream streamErr;
        streamErr << "Screen: Can't set video mode: " << SDL_GetError();
        throw std::runtime_error(streamErr.str());
    }
}

/// Destructeur : libération des ressources
Screen::~Screen(void)
{
    if (NULL != mpSurface)
    {
        SDL_FreeSurface(mpSurface);
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
