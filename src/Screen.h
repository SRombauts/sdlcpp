#include <SDL/SDL.h>

class Image;

class Screen
{
public:
    Screen (const int aWidth, const int aHeight, const char* apTitle);

    /// Blitte la surface sur l'écran
    bool blit(SDL_Surface* apSurface);

    /// Blitte l'image sur l'écran
    bool blit(Image& aImage);

    /// Mise à jour de l'écran
    bool flip(void);

private:
    SDL_Surface*    mpSurface;    //!< Surface de la fenêtre de l'application
    bool            mbValid;            //!< Valide si bien initialisée
};
