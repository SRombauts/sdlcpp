#pragma once

#include <SDL/SDL.h>

/**
 * @brief Encapsulation d'un rectangle x,y,w,h dans un SDL_Rect
 *
 * Ces 4 coordonnées sont considérées comme immuables.
 * Y ajoute une gestion des coordonnées x2=x+w et y2=y+h calculées une fois pour toute.
*/
class Rect
{
public:
             Rect(const int aX, const int aY, const unsigned int aW, const unsigned int aH);
    virtual ~Rect(void);

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
    inline unsigned int getH(void) const
    {
        return mRect.h;
    }
    inline unsigned int getW(void) const
    {
        return mRect.w;
    }
    inline int getX2(void) const
    {
        return mX2;
    }
    inline int getY2(void) const
    {
        return mY2;
    }

private:
    SDL_Rect    mRect;  //!< Rectangle (x,y,w,h) délimitant un morceau de surface
    int         mX2;    //!< X2=x+w calculée une fois pour toute à la construction
    int         mY2;    //!< Y2=y+h calculée une fois pour toute à la construction
};
