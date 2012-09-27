#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Animation.h"
#include "Sprite.h"
#include "Position.h"


/**
 * @brief Encapsulation d'une Entité
 *
 * Une Entity est la représentation générique d'un objet physique ou d'un être vivant animé
*/
class Entity
{
public:
             Entity(Sprite::Vector& aSpritesOrientation, Animation::Vector& aAnimationsOrientation);
    virtual ~Entity(void);

    enum Orientation
    {
        eOrientationRight   = 0,
        eOrientationBottom  = 1,
        eOrientationLeft    = 2,
        eOrientationTop     = 3
    };

    /// Accesseurs simples
    inline Sprite::Ptr getSprite(void)
    {
        return mSpritesOrientation[mOrientation];
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

    typedef boost::shared_ptr<Entity>    Ptr;
    typedef std::vector<Entity::Ptr>     Vector;

private:
    Sprite::Vector      mSpritesOrientation;    //!< Vecteur contenant les 4 sprites d'orientation
    Animation::Vector   mAnimationsOrientation; //!< Vecteur contenant les 4 animations d'orientation
    Position            mPosition;              //!< Position de l'Entity
    Orientation         mOrientation;           //!< Orientation courante
    int                 mSpeed;                 //!< Vitesse courante
};
