#pragma once

#include <SDL/SDL.h>

/**
 * @brief Encapsulation d'un rectangle (x,y) (w,h) dans un SDL_Rect
 *
 * Sert à encapsuler un SDL_Rect pour la source du blit d'un #Sprite.
 * Ces 4 coordonnées sont considérées comme immuables.
 *
 * @author 2012/09/27 SRombauts
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

private:
    SDL_Rect    mRect;  //!< Rectangle (x,y,w,h) délimitant un morceau de surface
};
