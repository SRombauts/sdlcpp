#include <SDL/SDL.h>

// TODO SRO : Réflechir à la logique des dépendances (Screen->Image ou Image->Screen ?)
class Image;

/// Objet RAII exception dans le constructeur en cas d'erreur : l'objet est toujours valide)
class Screen
{
public:
   Screen (const int aWidth, const int aHeight, const char* apTitle);
   ~Screen(void);

    /// Blitte la surface sur l'écran
    bool blit(SDL_Surface* apSurface);

    /// Blitte l'image sur l'écran
    bool blit(Image& aImage);

    /// Mise à jour de l'écran
    bool flip(void);

private:
    SDL_Surface*    mpSurface;   //!< Surface SDL de la fenêtre de l'application
};
