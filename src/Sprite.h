#pragma once

#include <SDL/SDL.h>
#include "Rect.h"

class Surface;

/**
 * @brief Encapsulation d'un sprite sur une surface SDL
 *
 * Un Sprite est un morceau de Surface rectangulaire.
*/
class Sprite
{
    friend class Screen;

public:
             Sprite(Surface& aSurface, const Sint16 aX, const Sint16 aY, const Uint16 aW, const Uint16 aH);
    virtual ~Sprite(void);

    /// Accesseurs simples
    inline       Surface&   getSurface(void)
    {
        return mSurface;
    }
    inline const Surface&   getSurface(void) const
    {
        return mSurface;
    }
    inline       Rect&      getRect(void)
    {
        return mRect;
    }
    inline const Rect&      getRect(void) const
    {
        return mRect;
    }

protected:
    Surface&    mSurface;   //!< Référence sur la Surface portant le Sprite
    Rect        mRect;      //!< Rectangle délimitant le Sprite dans la Surface
};
