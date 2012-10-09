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
 * @brief Encapsulation d'une Entité
 *
 * Une UnitPlayer est la représentation générique d'un objet physique ou d'un être vivant animé
 *
 * @author 2012/09/27 SRombauts
*/
class UnitPlayer : public IZoneCallbacks
{
public:
             // TODO SRombauts : problème, les Animations doivent être copiée !
             UnitPlayer(const Sprite::Vector&       aSpritesOrientation,
                    const Animation::Vector&    aAnimationsOrientation,
                    const Position&             aPosition,
                    const Offset&               aOffset,
                    const Size&                 aSize);
    virtual ~UnitPlayer(void);

    enum Orientation
    {
        eOrientationRight   = 0,
        eOrientationDown    = 1,
        eOrientationLeft    = 2,
        eOrientationUp      = 3
    };

    /// Met à jour la position selon l'orientation et la vitesse
    void move(void);

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

    typedef boost::shared_ptr<UnitPlayer>    Ptr;
    typedef std::vector<UnitPlayer::Ptr>     Vector;

private:
    // Méthodes dérivées de IZoneCallbacks
    virtual void onOver(bool& abAlreadyConsumed);
    virtual void onOut (bool& abAlreadyConsumed);
    virtual void onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed);
    virtual void onDrop(bool& abAlreadyConsumed);
    virtual void onClic(bool& abAlreadyConsumed);

private:
    Sprite::Vector      mSpritesOrientation;    //!< Vecteur pointant sur les 4 sprites d'orientation
    Animation::Vector   mAnimationsOrientation; //!< Vecteur pointant sur les 4 animations d'orientation
    Position            mPosition;              //!< Position absolue de l'UnitPlayer
    Offset              mOffset;                //!< Offset pour l'affichage de l'UnitPlayer #Coord)
    Coord               mCoord;                 //!< Coordonnées de l'UnitPlayer dans sa surface parent
    Zone                mZone;                  //!< Zone cliquable à l'écran
    Orientation         mOrientation;           //!< Orientation courante
    int                 mSpeed;                 //!< Vitesse courante
};
