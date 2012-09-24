#pragma once

#include <SDL/SDL.h>

/**
 * @brief Encapsulation d'une surface SDL
 *
 * RAII ; gère la libération mémoire dans le destructeur
*/
class Surface
{
    friend class Screen;

public:
             Surface(void);
    virtual ~Surface(void);

    /// Blitte une surface sur la surface courante
    bool blit(Surface& aSurface);

private:
    /// @{ Interdiction de la copie d'instance
    Surface             (const Surface& aInstance);
    Surface& operator=  (const Surface& aInstance);
    /// @}

protected:
    SDL_Surface*    mpSurface;   //!< Pointeur vers la surface SDL
};
