#include <stdexcept>
#include <iostream>

#include "UnitPlayer.h"
#include "Screen.h"
#include "Size.h"

/// RAII : garantie qu'une animation est toujours valide (dispose au moins d'un Sprite)
UnitPlayer::UnitPlayer(const Sprite::Vector&    aSpritesOrientation,
               const Animation::Vector& aAnimationsOrientation,
               const Position&          aPosition,
               const Offset&            aOffset,
               const Size&              aSize) :
    mSpritesOrientation(aSpritesOrientation),
    mAnimationsOrientation(aAnimationsOrientation),
    mPosition(aPosition),
    mOffset(aOffset),
    mCoord(aPosition.getX()+aOffset.getX(), aPosition.getY()+aOffset.getY()),
    mZone(*this,
          aPosition.getX()+aOffset.getX(), aPosition.getY()+aOffset.getY(),
          aSize.getW(), aSize.getH()),
    mOrientation(eOrientationRight),
    mSpeed(0)
{
    if (4 != aSpritesOrientation.size())
    {
        throw std::runtime_error("UnitPlayer::UnitPlayer: 4 != aSpritesOrientation.size()");
    }
    if (4 != aAnimationsOrientation.size())
    {
        throw std::runtime_error("UnitPlayer::UnitPlayer: 4 != aAnimationsOrientation.size()");
    }
}

UnitPlayer::~UnitPlayer(void)
{
}

void UnitPlayer::move(void)
{
    switch (mOrientation)
    {
        case UnitPlayer::eOrientationRight:
            mPosition.incr(mSpeed, 0);
            break;
        case UnitPlayer::eOrientationDown:
            mPosition.incr(0, mSpeed);
            break;
        case UnitPlayer::eOrientationLeft:
            mPosition.incr(-mSpeed, 0);
            break;
        case UnitPlayer::eOrientationUp:
            mPosition.incr(0, -mSpeed);
            break;
        default:
            ;
    }
    mCoord.set(mPosition.getX()+mOffset.getX(), mPosition.getY()+mOffset.getY());
    mZone.set (mPosition.getX()+mOffset.getX(), mPosition.getY()+mOffset.getY());
}

void UnitPlayer::show(Screen& aScreen)
{
    if (0 == mSpeed)
    {
        aScreen.blit(*(getSprite()), mCoord);
    }
    else
    {
        aScreen.blit(*(getAnimation())->getSprite(), mCoord);
    }
}

void UnitPlayer::onOver(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitPlayer::onOver(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitPlayer::onOut (bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitPlayer::onOut(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitPlayer::onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitPlayer::onDrag(aX=" << aX << ", aY="  << aY << ", abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitPlayer::onDrop(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitPlayer::onDrop(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UnitPlayer::onClic(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UnitPlayer::onClic(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

