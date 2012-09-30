#include <stdexcept>

#include "Entity.h"
#include <iostream>
#include "Sprite.h"


/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
Entity::Entity(const Sprite::Vector&    aSpritesOrientation,
               const Animation::Vector& aAnimationsOrientation,
               const Coord&             aCoord) :
    Zone(aCoord.getX(), aCoord.getY(), aSpritesOrientation[0]->getRect().getW(), aSpritesOrientation[0]->getRect().getH()),
    mSpritesOrientation(aSpritesOrientation),
    mAnimationsOrientation(aAnimationsOrientation),
    mCoord(aCoord),
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

void Entity::move(void)
{
    switch (mOrientation)
    {
        case Entity::eOrientationRight:
            mCoord.incr(mSpeed, 0);
            break;
        case Entity::eOrientationDown:
            mCoord.incr(0, mSpeed);
            break;
        case Entity::eOrientationLeft:
            mCoord.incr(-mSpeed, 0);
            break;
        case Entity::eOrientationUp:
            mCoord.incr(0, -mSpeed);
            break;
        default:
            ;
    }
}

void Entity::onOver(const bool abIsOver)
{
    std::cout << "Entity::onOver: onHoover(abIsOver=" << abIsOver << ")" << std::endl;
}
