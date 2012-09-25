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
             Surface(const Sint16 aOffsetX = 0, const Sint16 aOffsetY = 0);
    virtual ~Surface(void);

    /// Blitte une surface sur la surface courante
    bool blit(Surface& aSurface);

    /// Met à jour l'offset
    void set(const Sint16 aOffsetX = 0, const Sint16 aOffsetY = 0);

    /// Accesseurs simples
    inline const SDL_Surface&   getSurface(void) const
    {
        return *mpSurface; // Jamais NULL une fois l'objet construit
    }
    inline       SDL_Rect&      getOffset(void)
    {
        return mOffset;
    }
    inline const SDL_Rect&      getOffset(void) const
    {
        return mOffset;
    }

private:
    /// @{ Interdiction de la copie d'instance
    Surface             (const Surface& aInstance);
    Surface& operator=  (const Surface& aInstance);
    /// @}

protected:
    SDL_Surface*    mpSurface;  //!< Pointeur vers la surface SDL
    SDL_Rect        mOffset;    //!< Offset (x,y) de la surface dans sa surface parent
};
