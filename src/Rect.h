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
             Rect(const Sint16 aX, const Sint16 aY, const Uint16 aW, const Uint16 aH);
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
    inline Sint16 getX(void) const
    {
        return mRect.x;
    }
    inline Sint16 getY(void) const
    {
        return mRect.y;
    }
    inline Sint16 getH(void) const
    {
        return mRect.h;
    }
    inline Sint16 getW(void) const
    {
        return mRect.w;
    }
    inline Sint16 getX2(void) const
    {
        return mX2;
    }
    inline Sint16 getY2(void) const
    {
        return mY2;
    }

private:
    SDL_Rect    mRect;  //!< Rectangle (x,y,w,h) délimitant un morceau de surface
    Sint16      mX2;    //!< X2=x+w calculée une fois pour toute à la construction
    Sint16      mY2;    //!< Y2=y+h calculée une fois pour toute à la construction
};
