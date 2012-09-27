#include <stdexcept>

#include "Entity.h"
#include "Sprite.h"


/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
Entity::Entity(Sprite::Vector& aSpritesOrientation, Animation::Vector& aAnimationsOrientation) :
    mSpritesOrientation(aSpritesOrientation),
    mAnimationsOrientation(aAnimationsOrientation),
    mCurrentOrientation(eOrientationRight),
    mCurrentSpeed(0)
{
    if (4 != aSpritesOrientation.size())
    {
        throw std::runtime_error("Entity::Entity: 4 != aSpritesOrientation.size()");
    }
    if (4 != aAnimationsOrientation.size())
    {
        throw std::runtime_error("Entity::Entity: 4 != aAnimationsOrientation.size()");
    }
}

Entity::~Entity(void)
{
}
