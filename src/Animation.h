#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Sprite.h"


/**
 * @brief Encapsulation d'une liste de Sprites
 *
 * Une Animation est une séquence ordonnée (éventuellement répétable) de Sprite à afficher successivement.
*/
class Animation
{
public:
             Animation(Sprite::Ptr& aSpritePtr);
    virtual ~Animation(void);

    unsigned long addSprite(Sprite::Ptr& aSpritePtr);

    // Incrémente l'index du sprite courant
    unsigned long next(void);

    /// Accesseurs simples
    inline unsigned long getIndex(void)
    {
        return mIndex;
    }
    inline unsigned long setIndex(unsigned long aIndex)
    {
        return mIndex = (aIndex%mSpriteVector.size());
    }
    inline Sprite::Ptr getSprite(void)
    {
        return mSpriteVector[mIndex];
    }
    inline Sprite::Ptr getSprite(unsigned long aIndex)
    {
        return mSpriteVector[aIndex];
    }

    typedef std::vector<Sprite::Ptr>        SpriteVector;

    typedef boost::shared_ptr<Animation>    Ptr;

private:
    SpriteVector    mSpriteVector;  //!< Liste des Sprites de l'Animation
    unsigned long   mIndex;         //!< Index du Sprite courant dans l'Animation
};
