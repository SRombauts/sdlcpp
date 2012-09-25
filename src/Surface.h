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
             Surface(const Sint16 aX = 0, const Sint16 aY = 0);
    virtual ~Surface(void);

    /// Blitte une surface sur la surface courante
    bool blit(Surface& aSurface);

    /// Met à jour l'offset
    void set(const Sint16 aX = 0, const Sint16 aY = 0);

    /// Accesseurs simples
    inline SDL_Rect& getOffset(void)
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
