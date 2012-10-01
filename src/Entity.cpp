#include <stdexcept>

#include "Entity.h"
#include <iostream>
#include "Sprite.h"


/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
Entity::Entity(const Sprite::Vector&    aSpritesOrientation,
               const Animation::Vector& aAnimationsOrientation,
               const Position&          aPosition,
               const Offset&            aOffset) :
    mSpritesOrientation(aSpritesOrientation),
    mAnimationsOrientation(aAnimationsOrientation),
    mPosition(aPosition),
    mOffset(aOffset),
    mCoord(aPosition.getX()+aOffset.getX(), aPosition.getY()+aOffset.getY()),
    mZone(*this,
          aPosition.getX()+aOffset.getX(), aPosition.getY()+aOffset.getY(),
          aSpritesOrientation[0]->getRect().getW(), aSpritesOrientation[0]->getRect().getH()),
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
            mPosition.incr(mSpeed, 0);
            break;
        case Entity::eOrientationDown:
            mPosition.incr(0, mSpeed);
            break;
        case Entity::eOrientationLeft:
            mPosition.incr(-mSpeed, 0);
            break;
        case Entity::eOrientationUp:
            mPosition.incr(0, -mSpeed);
            break;
        default:
            ;
    }
    mCoord.set(mPosition.getX()+mOffset.getX(), mPosition.getY()+mOffset.getY());
    mZone.set (mPosition.getX()+mOffset.getX(), mPosition.getY()+mOffset.getY());
}

void Entity::onOver(const bool abIsOver, bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "Entity::onOver: onHoover(abIsOver=" << abIsOver << ", abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}
