#include <SDL/SDL.h>

class Screen;

/// Objet RAII exception dans le constructeur en cas d'erreur : l'objet est toujours valide)
class Image
{
    friend class Screen;

public:
             Image(const char* apFileName);
    virtual ~Image(void);

private:
    SDL_Surface*    mpSurface;   //!< Surface SDL de la fenêtre de l'application
};
