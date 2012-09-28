#include <stdexcept>

#include "Animation.h"
#include "Sprite.h"


/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
Animation::Animation(Sprite::Vector& aSpriteVector, unsigned long aIndex /* = 0 */) :
    mSpriteVector(aSpriteVector),
    mIndex(aIndex)
{
    if (0 == aSpriteVector.size())
    {
        throw std::runtime_error("Animation::Animation: aSpriteVector de taille nulle !");
    }
}

Animation::~Animation(void)
{
}

// Incrémente l'index du Sprite courant, et repasse à zéro en cas de dépassement
/*
unsigned long Animation::next(void)
{
    mIndex++;
    mIndex = mIndex % mSpriteVector.size();
    return mIndex;
}
*/
