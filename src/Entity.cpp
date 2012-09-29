#include <stdexcept>

#include "Entity.h"
#include "Sprite.h"


/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
Entity::Entity(const Sprite::Vector&    aSpritesOrientation,
               const Animation::Vector& aAnimationsOrientation,
               const Position&          aPosition) :
    Zone(aPosition.getX(), aPosition.getY(), aSpritesOrientation[0]->getRect().getW(), aSpritesOrientation[0]->getRect().getH()),
    mSpritesOrientation(aSpritesOrientation),
    mAnimationsOrientation(aAnimationsOrientation),
    mPosition(aPosition),
    mOrientation(eOrientationRight),
    mSpeed(0)
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
