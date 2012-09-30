#pragma once

#include <SDL/SDL.h>

/**
 * @brief Encapsulation de coordonnées (x,y) dans un SDL_Rect
 *
 * Sert à décrire un offset (x,y) pour la destination du blit d'une #Surface.
 * Les membres w et h sont considérés comme immuables et initialisés à zéro.
 * Les deux coordonnées (x,y) peuvent être mise à jour.
 *
 * @author 2012/09/26 SRombauts
*/
class Coord
{
public:
             Coord(const int aX = 0, const int aY = 0);
    virtual ~Coord(void);

    /// Met à jour les coordonnées (x,y)
    void set (const int aX,     const int aY);
    void incr(const int aIncrX, const int aIncrY);

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
    SDL_Rect    mRect;  //!< Rect contenant les coordonnées (x,y)
};
