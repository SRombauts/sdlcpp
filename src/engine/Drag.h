#pragma once

#include <SDL/SDL.h>

#include "Coord.h"
#include "Sprite.h"

class Screen;

/**
 * @brief Encapsulation d'un élément d'UI en cours de Drag and Drop
 *
 * @author 2012/10/03 SRombauts
*/
class Drag
{
public:
    Drag(const Sprite::Ptr&  aSpritePtr);
    virtual ~Drag(void);

    /// Affichage sur l'écran
    void show(Screen& aScreen);

    /// Accesseurs simples
    inline       Sprite::Ptr& getSprite(void)
    {
        return mSpritePtr;
    }
    inline const Sprite::Ptr& getSprite(void) const
    {
        return mSpritePtr;
    }
    inline       Coord& getCoord(void)
    {
        return mCoord;
    }
    inline const Coord& getCoord(void) const
    {
        return mCoord;
    }
    inline void setVisible(const bool abIsVisible)
    {
        mbIsVisible = abIsVisible;
    }
    inline bool isVisible(void) const
    {
        return mbIsVisible;
    }

private:
    Sprite::Ptr mSpritePtr; //!< Sprite de Drag and Drop
    Coord       mCoord;     //!< Coordonnées sur l'écran
    bool        mbIsVisible;//!< Indicateur d'affichage
};
