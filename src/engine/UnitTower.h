#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Animation.h"
#include "Coord.h"
#include "Offset.h"
#include "Position.h"
#include "Sprite.h"
#include "Zone.h"
#include "ZoneCallbacks.h"

class Screen;
class Size;

/**
 * @brief Encapsulation d'une tourelle
 *
 * @author 2012/10/09 SRombauts
*/
class UnitTower : public IZoneCallbacks
{
public:
             UnitTower(const Sprite::Vector&       aSpritesOrientation,
                        const Position&             aPosition,
                        const Offset&               aOffset,
                        const Size&                 aSize);
    virtual ~UnitTower(void);

    enum Orientation
    {
        eOrientationRight   = 0,
        eOrientationDown    = 1,
        eOrientationLeft    = 2,
        eOrientationUp      = 3
    };

    /// Affichage sur l'écran
    void show(Screen& aScreen);

    /// Accesseurs simples
    inline       Sprite::Ptr& getSprite(void)
    {
         return mSpritesOrientation[mOrientation];
    }
    inline const Sprite::Ptr& getSprite(void) const
    {
         return mSpritesOrientation[mOrientation];
    }
    inline       Position& getPosition(void)
    {
        return mPosition;
    }
    inline const Position& getPosition(void) const
    {
        return mPosition;
    }
    inline       Coord& getCoord(void)
    {
        return mCoord;
    }
    inline const Coord& getCoord(void) const
    {
        return mCoord;
    }
    inline       Zone& getZone(void)
    {
        return mZone;
    }
    inline const Zone& getZone(void) const
    {
        return mZone;
    }
    inline       Orientation& getOrientation(void)
    {
        return mOrientation;
    }
    inline const Orientation& getOrientation(void) const
    {
        return mOrientation;
    }
    inline void setOrientation(const Orientation& aOrientation)
    {
        mOrientation = aOrientation;
    }
    typedef boost::shared_ptr<UnitTower>    Ptr;
    typedef std::vector<UnitTower::Ptr>     Vector;

private:
    // Méthodes dérivées de IZoneCallbacks
    virtual void onOver(bool& abAlreadyConsumed);
    virtual void onOut (bool& abAlreadyConsumed);
    virtual void onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed);
    virtual void onDrop(bool& abAlreadyConsumed);
    virtual void onClic(bool& abAlreadyConsumed);

private:
    Sprite::Vector      mSpritesOrientation;    //!< Vecteur pointant sur les 4 sprites d'orientation
    Position            mPosition;              //!< Position absolue de l'UnitTower
    Offset              mOffset;                //!< Offset pour l'affichage de l'UnitTower #Coord)
    Coord               mCoord;                 //!< Coordonnées de l'UnitTower dans sa surface parent
    Zone                mZone;                  //!< Zone cliquable à l'écran
    Orientation         mOrientation;           //!< Orientation courante
};
