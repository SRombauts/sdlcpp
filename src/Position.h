#pragma once

#include <SDL/SDL.h>

/**
 * @brief Encapsulation d'une position x,y dans un SDL_Rect
 *
 * Empêche d'utiliser à tord les membres w et h de SDL_Rect
*/
class Position
{
    friend class Screen;

public:
             Position(const Sint16 aX = 0, const Sint16 aY = 0);
    virtual ~Position(void);

    /// Met à jour la position
    void set(const Sint16 aX = 0, const Sint16 aY = 0);
    void incr(const Sint16 aIncrX = 0, const Sint16 aIncrY = 0);

    /// Accesseurs simples
    inline       SDL_Rect&  getRect(void)
    {
        return mRect;
    }
    inline const SDL_Rect&  getRect(void) const
    {
        return mRect;
    }

protected:
    SDL_Rect    mRect;  //!< Rect contenant la position (x,y)
};
