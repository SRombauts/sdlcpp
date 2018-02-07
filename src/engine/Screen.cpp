#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Screen.h"
#include "Image.h"

/// Les paramètres de notre écran
const int SCREEN_BPP    = 32;

/// Constructeur RAII (exception en cas d'erreur : l'objet est toujours valide)
Screen::Screen(const int aWidth, const int aHeight, const char* apTitle) :
    Surface()
{
    // Chargement de l'icône AVANT SDL_SetVideoMode
    SDL_Surface* pSurfaceIcon = SDL_LoadBMP("res/sdl_icone.bmp");
    if (nullptr != pSurfaceIcon)
    {
        SDL_WM_SetIcon(pSurfaceIcon, nullptr);
    }
    else
    {
        std::cout << "Screen: Can't load Icon: " << SDL_GetError() << std::endl;
    }

    // Initialisation de la fenêtre principale
    mpSurface = SDL_SetVideoMode(aWidth, aHeight, SCREEN_BPP, SDL_HWSURFACE);
    if (nullptr != mpSurface)
    {
        // Mise en place de sa barre de titre
        SDL_WM_SetCaption(apTitle, nullptr);
    }
    else
    {
        std::ostringstream streamErr;
        streamErr << "Screen: Can't set video mode: " << SDL_GetError() << std::endl;
        throw std::runtime_error(streamErr.str());
    }
}

/// Destructeur : libération des ressources
Screen::~Screen(void)
{
}

/// Mise à jour de l'écran
bool Screen::flip(void)
{
    bool bRet = (0 == SDL_Flip(mpSurface));
    if (false == bRet)
    {
       std::cout << "Flip error: " << SDL_GetError() << std::endl;
    }
    return bRet;
}
