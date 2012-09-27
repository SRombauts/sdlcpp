#pragma once

#include <SDL/SDL.h>

class Position;
class Sprite;

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

    /// Blit une surface sur la surface courante
    bool blit(Surface& aSurface);
    bool blit(Surface& aSurface, Position& aOffset);
    bool blit(Sprite&  aSprite,  Position& aOffset);

    /// Accesseurs simples
    inline const SDL_Surface&   getSurface(void) const
    {
        return *mpSurface; // Jamais NULL une fois l'objet construit
    }
    inline       SDL_Surface&   getSurface(void)
    {
        return *mpSurface; // Jamais NULL une fois l'objet construit
    }
    inline int getW(void) const
    {
        return (*mpSurface).w; // Jamais NULL une fois l'objet construit
    }
    inline int getH(void) const
    {
        return (*mpSurface).h; // Jamais NULL une fois l'objet construit
    }

private:
    /// @{ Interdiction de la copie d'instance, car cette classe gère une ressource allouée dynamiquement
    Surface             (const Surface& aInstance);
    Surface& operator=  (const Surface& aInstance);
    /// @}

protected:
    SDL_Surface*    mpSurface;  //!< Pointeur vers la surface SDL
};
