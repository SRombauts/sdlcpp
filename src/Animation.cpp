#include <stdexcept>

#include "Animation.h"
#include "Sprite.h"


/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
Animation::Animation(Sprite::Ptr& aSpritePtr) :
    mIndex(0)
{
    if (aSpritePtr)
    {
        mSpriteVector.push_back(aSpritePtr);
    }
    else
    {
        throw std::runtime_error("Animation::Animation: aSpritePtr NULL !");
    }
}

Animation::~Animation(void)
{
}

/// Ajoute un sprite à la fin de la séquence animée, et retourne son index
unsigned long Animation::addSprite(Sprite::Ptr& aSpritePtr)
{
    if (aSpritePtr)
    {
        mSpriteVector.push_back(aSpritePtr);
    }
    else
    {
        throw std::runtime_error("Animation::addSprite: aSpritePtr NULL !");
    }

    return (mSpriteVector.size() - 1);
}

// Incrémente l'index du Sprite courant, et repasse à zéro en cas de dépassement
unsigned long Animation::next(void)
{
    mIndex++;
    mIndex = mIndex % mSpriteVector.size();
    return mIndex;
}
