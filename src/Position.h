#pragma once

#include <SDL/SDL.h>

/**
 * @brief Encapsulation d'une position x,y dans un SDL_Rect
 *
 * Empêche d'utiliser à tord les membres w et h de SDL_Rect
*/
class Position
{
public:
             Position(const int aX = 0, const int aY = 0);
    virtual ~Position(void);

    /// Met à jour la position
    void set(const int aX = 0, const int aY = 0);
    void incr(const int aIncrX = 0, const int aIncrY = 0);

    /// Accesseurs simples
    inline       SDL_Rect&  getRect(void)
    {
        return mRect;
    }
    inline const SDL_Rect&  getRect(void) const
    {
        return mRect;
    }
    inline int getX(void) const
    {
        return mRect.x;
    }
    inline int getY(void) const
    {
        return mRect.y;
    }

private:
    SDL_Rect    mRect;  //!< Rect contenant la position (x,y)
};
