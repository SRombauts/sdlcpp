#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <memory>

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
 * @brief Encapsulation d'une unité ennemie
 *
 * @author 2012/10/09 SRombauts
*/
class UnitEnemy : public IZoneCallbacks
{
public:
             // TODO SRombauts : problème, les Animations doivent être copiée !
             UnitEnemy(const Animation::Vector& aAnimationsOrientation,
                       const Position&          aPosition,
                       const Offset&            aOffset,
                       const Size&              aSize,
                       const int                aSpeed);
    virtual ~UnitEnemy(void);

    enum Orientation
    {
        eOrientationRight   = 0,
        eOrientationDown    = 1,
        eOrientationLeft    = 2,
        eOrientationUp      = 3
    };

    /// Met à jour la position selon l'orientation et la vitesse
    void move(unsigned int aDeltaTime);

    /// Affichage sur l'écran
    void show(Screen& aScreen);

    /// Accesseurs simples
    inline       Animation::Ptr& getAnimation(void)
    {
        return mAnimationsOrientation[mOrientation];
    }
    inline const Animation::Ptr& getAnimation(void) const
    {
        return mAnimationsOrientation[mOrientation];
    }
    inline void setCoord(const Position& aPosition)
    {
        mPosition = aPosition;
    }
    inline       Position& getPosition(void)
    {
        return mPosition;
    }
    inline const Position& getPosition(void) const
    {
        return mPosition;
    }
    inline void setCoord(const Coord& aCoord)
    {
        mCoord = aCoord;
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
    inline int getSpeed(void) const
    {
        return mSpeed;
    }
    inline void setSpeed(const int aSpeed)
    {
        mSpeed = aSpeed;
    }

    typedef std::shared_ptr<UnitEnemy>    Ptr;
    typedef std::vector<UnitEnemy::Ptr>     Vector;

private:
    // Méthodes dérivées de IZoneCallbacks
    virtual void onOver(bool& abAlreadyConsumed);
    virtual void onOut (bool& abAlreadyConsumed);
    virtual void onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed);
    virtual void onDrop(bool& abAlreadyConsumed);
    virtual void onClic(bool& abAlreadyConsumed);

private:
    Animation::Vector   mAnimationsOrientation; //!< Vecteur pointant sur les 4 animations d'orientation
    Position            mPosition;              //!< Position absolue de l'UnitEnemy
    Offset              mOffset;                //!< Offset pour l'affichage de l'UnitEnemy #Coord)
    Coord               mCoord;                 //!< Coordonnées de l'UnitEnemy dans sa surface parent
    Zone                mZone;                  //!< Zone cliquable à l'écran
    Orientation         mOrientation;           //!< Orientation courante
    int                 mSpeed;                 //!< Vitesse courante
};
