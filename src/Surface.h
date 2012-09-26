#pragma once

#include <SDL/SDL.h>

class Position;

/**
 * @brief Encapsulation d'une surface SDL
 *
 * RAII ; gère la libération mémoire dans le destructeur
*/
class Surface
{
    friend class Screen;

public:
             Surface();
    virtual ~Surface(void);

    /// Blitte une surface sur la surface courante
    bool blit(Surface& aSurface);
    bool blit(Surface& aSurface, Position& aOffset);

    /// Accesseurs simples
    inline const SDL_Surface&   getSurface(void) const
    {
        return *mpSurface; // Jamais NULL une fois l'objet construit
    }

private:
    /// @{ Interdiction de la copie d'instance
    Surface             (const Surface& aInstance);
    Surface& operator=  (const Surface& aInstance);
    /// @}

protected:
    SDL_Surface*    mpSurface;  //!< Pointeur vers la surface SDL
};
