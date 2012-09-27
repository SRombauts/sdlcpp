#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Sprite.h"
#include "Animation.h"


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
        return mSpritesOrientation[mCurrentOrientation];
    }

    typedef boost::shared_ptr<Entity>    Ptr;
    typedef std::vector<Entity::Ptr>     Vector;

private:
    Sprite::Vector      mSpritesOrientation;    //!< Vecteur contenant les 4 sprites d'orientation
    Animation::Vector   mAnimationsOrientation; //!< Vecteur contenant les 4 animations d'orientation
    Orientation         mCurrentOrientation;    //!< Orientation courante
    int                 mCurrentSpeed;          //!< Vitesse courante
};
