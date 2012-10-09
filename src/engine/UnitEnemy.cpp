#include <stdexcept>
#include <iostream>

#include "UnitEnemy.h"
#include "Screen.h"
#include "Size.h"

/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
UnitEnemy::UnitEnemy(const Animation::Vector& aAnimationsOrientation,
                     const Position&          aPosition,
                     const Offset&            aOffset,
                     const Size&              aSize,
                     const int                aSpeed) :
    mAnimationsOrientation(aAnimationsOrientation),
    mPosition(aPosition),
    mOffset(aOffset),
    mCoord(aPosition.getX()+aOffset.getX(), aPosition.getY()+aOffset.getY()),
    mZone(*this,
          aPosition.getX()+aOffset.getX(), aPosition.getY()+aOffset.getY(),
          aSize.getW(), aSize.getH()),
    mOrientation(eOrientationRight),
    mSpeed(aSpeed)
{
    if (4 != aAnimationsOrientation.size())
    {
        throw std::runtime_error("UnitEnemy::UnitEnemy: 4 != aAnimationsOrientation.size()");
    }
}

UnitEnemy::~UnitEnemy(void)
{
}

void UnitEnemy::move(unsigned int aDeltaTimeMs)
{
    switch (mOrientation)
    {
        case UnitEnemy::eOrientationRight:
            mPosition.incr((mSpeed*aDeltaTimeMs)/1000, 0);
            break;
        case UnitEnemy::eOrientationDown:
            mPosition.incr(0, (mSpeed*aDeltaTimeMs)/1000);
            break;
        case UnitEnemy::eOrientationLeft:
            mPosition.incr(-(mSpeed*aDeltaTimeMs)/1000, 0);
            break;
        case UnitEnemy::eOrientationUp:
            mPosition.incr(0, -(mSpeed*aDeltaTimeMs)/1000);
            break;
        default:
            ;
    }
    mCoord.set(mPosition.getX()+mOffset.getX(), mPosition.getY()+mOffset.getY());
    mZone.set (mPosition.getX()+mOffset.getX(), mPosition.getY()+mOffset.getY());
}

void UnitEnemy::show(Screen& aScreen)
{
    aScreen.blit(*(getAnimation())->getSprite(), mCoord);
}

void UnitEnemy::onOver(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitEnemy::onOver(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitEnemy::onOut (bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitEnemy::onOut(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitEnemy::onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitEnemy::onDrag(aX=" << aX << ", aY="  << aY << ", abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitEnemy::onDrop(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitEnemy::onDrop(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitEnemy::onClic(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitEnemy::onClic(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

