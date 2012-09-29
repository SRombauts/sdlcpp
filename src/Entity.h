#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Animation.h"
#include "Sprite.h"
#include "Position.h"
#include "Zone.h"

/**
 * @brief Encapsulation d'une Entité
 *
 * Une Entity est la représentation générique d'un objet physique ou d'un être vivant animé
 *
 * @author 2012/09/27 SRombauts
*/
class Entity : public Zone
{
public:
             Entity(const Sprite::Vector&       aSpritesOrientation,
                    const Animation::Vector&    aAnimationsOrientation,
                    const Position&             aPosition);
    virtual ~Entity(void);

    enum Orientation
    {
        eOrientationRight   = 0,
        eOrientationDown    = 1,
        eOrientationLeft    = 2,
        eOrientationUp      = 3
    };

    /// Accesseurs simples
    inline Sprite::Ptr getSprite(void)
    {
        return mSpritesOrientation[mOrientation];
    }
    inline Animation::Ptr getAnimation(void)
    {
        return mAnimationsOrientation[mOrientation];
    }
    inline void setPosition(const Position& aPosition)
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
    inline int getSpeed(void)
    {
        return mSpeed;
    }
    inline int getSpeed(void) const
    {
        return mSpeed;
    }
    inline void setSpeed(const int aSpeed)
    {
        mSpeed = aSpeed;
    }

    typedef boost::shared_ptr<Entity>    Ptr;
    typedef std::vector<Entity::Ptr>     Vector;

protected:
    virtual void onOver(const bool abIsOver);

private:
    Sprite::Vector      mSpritesOrientation;    //!< Vecteur contenant les 4 sprites d'orientation
    Animation::Vector   mAnimationsOrientation; //!< Vecteur contenant les 4 animations d'orientation
    Position            mPosition;              //!< Position de l'Entity
    Orientation         mOrientation;           //!< Orientation courante
    int                 mSpeed;                 //!< Vitesse courante
};
