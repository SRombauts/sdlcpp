#pragma once

#include <SDL/SDL.h>
#include <memory>
#include <vector>

#include "Rect.h"
#include "Surface.h"

/**
 * @brief Encapsulation d'un sprite sur une surface SDL
 *
 * Un Sprite est un morceau de Surface rectangulaire.
 *
 * @author 2012/09/27 SRombauts
*/
class Sprite
{
public:
             Sprite(const Surface::Ptr& aSurfacePtr,
                    const int           aX,
                    const int           aY,
                    const unsigned int  aW,
                    const unsigned int  aH);
    virtual ~Sprite(void);

    /// Accesseurs simples
    inline       Surface&   getSurface(void)
    {
        return *mSurfacePtr;
    }
    inline const Surface&   getSurface(void) const
    {
        return *mSurfacePtr;
    }
    inline       Rect&      getRect(void)
    {
        return mRect;
    }
    inline const Rect&      getRect(void) const
    {
        return mRect;
    }

    typedef std::shared_ptr<Sprite>   Ptr;
    typedef std::vector<Sprite::Ptr>    Vector;

private:
    Surface::Ptr    mSurfacePtr;//!< Pointeur sur la Surface portant le Sprite (toujours valable, RAII)
    Rect            mRect;      //!< Rectangle délimitant le Sprite dans la Surface
};
