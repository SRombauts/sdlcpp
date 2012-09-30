#pragma once

#include <SDL/SDL.h>
#include <boost/shared_ptr.hpp>

class Coord;
class Sprite;

/**
 * @brief Encapsulation d'une surface SDL
 *
 * RAII ; gère la libération mémoire dans le destructeur
 *
 * @author 2012/09/24 SRombauts
*/
class Surface
{
public:
             Surface(void);
    virtual ~Surface(void);

    /// Blit une surface sur la surface courante
    bool blit(Surface& aSurface);
    bool blit(Surface& aSurface, Coord& aOffset);
    bool blit(Sprite&  aSprite,  Coord& aOffset);

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

    typedef boost::shared_ptr<Surface>  Ptr;

private:
    /// @{ Interdiction de la copie d'instance, car cette classe gère une ressource allouée dynamiquement
    Surface             (const Surface& aInstance);
    Surface& operator=  (const Surface& aInstance);
    /// @}

protected:
    SDL_Surface*    mpSurface;  //!< Pointeur vers la surface SDL
};
