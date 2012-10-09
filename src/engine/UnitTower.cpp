#include <stdexcept>
#include <iostream>

#include "UnitTower.h"
#include "Screen.h"
#include "Size.h"

/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
UnitTower::UnitTower(const Sprite::Vector&    aSpritesOrientation,
                     const Position&          aPosition,
                     const Offset&            aOffset,
                     const Size&              aSize) :
    mSpritesOrientation(aSpritesOrientation),
    mPosition(aPosition),
    mOffset(aOffset),
    mCoord(aPosition.getX()+aOffset.getX(), aPosition.getY()+aOffset.getY()),
    mZone(*this,
          aPosition.getX()+aOffset.getX(), aPosition.getY()+aOffset.getY(),
          aSize.getW(), aSize.getH()),
    mOrientation(eOrientationRight)
{
    if (4 != aSpritesOrientation.size())
    {
        throw std::runtime_error("UnitTower::UnitTower: 4 != aSpritesOrientation.size()");
    }
}

UnitTower::~UnitTower(void)
{
}

void UnitTower::show(Screen& aScreen)
{
    aScreen.blit(*(getSprite()), mCoord);
}

void UnitTower::onOver(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitTower::onOver(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitTower::onOut (bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitTower::onOut(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitTower::onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitTower::onDrag(aX=" << aX << ", aY="  << aY << ", abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitTower::onDrop(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitTower::onDrop(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitTower::onClic(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitTower::onClic(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

