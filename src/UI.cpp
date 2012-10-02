#include <stdexcept>
#include <iostream>

#include "UI.h"


/// RAII : garantie qu'un élément d'UI est toujours valide (dispose au moins d'un Sprite)
UI::UI(const Sprite::Ptr&   aSpriteDefaultPtr,
       const Coord&         aCoord,
       const State          aState /* = eStateDefault */) :
    mCoord(aCoord),
    mZone(*this,
          aCoord.getX(), aCoord.getY(),
          aSpriteDefaultPtr->getRect().getW(), aSpriteDefaultPtr->getRect().getH()),
    mState(aState)
{
    if (!aSpriteDefaultPtr)
    {
        throw std::runtime_error("UI::UI: aSpriteDefaultPtr NULL");
    }
    mSprites.push_back(aSpriteDefaultPtr);  // eStateDefault   = 0,
    mSprites.push_back(aSpriteDefaultPtr);  // eStateDown      = 1,
    mSprites.push_back(aSpriteDefaultPtr);  // eStateFocus     = 2,
    mSprites.push_back(aSpriteDefaultPtr);  // eStateDisabled  = 3
}

UI::UI(const Sprite::Ptr&   aSpriteDefaultPtr,
       const Sprite::Ptr&   aSpriteDownPtr,
       const Coord&         aCoord,
       const State          aState /* = eStateDefault */) :
    mCoord(aCoord),
    mZone(*this,
          aCoord.getX(), aCoord.getY(),
          aSpriteDefaultPtr->getRect().getW(), aSpriteDefaultPtr->getRect().getH()),
    mState(aState)
{
    if (!aSpriteDefaultPtr || !aSpriteDownPtr)
    {
        throw std::runtime_error("UI::UI: aSpriteDefaultPtr NULL");
    }
    mSprites.push_back(aSpriteDefaultPtr);  // eStateDefault   = 0,
    mSprites.push_back(aSpriteDownPtr);     // eStateDown      = 1,
    mSprites.push_back(aSpriteDefaultPtr);  // eStateFocus     = 2,
    mSprites.push_back(aSpriteDefaultPtr);  // eStateDisabled  = 3
}

UI::UI(const Sprite::Ptr&   aSpriteDefaultPtr,
       const Sprite::Ptr&   aSpriteDownPtr,
       const Sprite::Ptr&   aSpriteFocusPtr,
       const Coord&         aCoord,
       const State          aState /* = eStateDefault */) :
    mCoord(aCoord),
    mZone(*this,
          aCoord.getX(), aCoord.getY(),
          aSpriteDefaultPtr->getRect().getW(), aSpriteDefaultPtr->getRect().getH()),
    mState(aState)
{
    if (!aSpriteDefaultPtr || !aSpriteDownPtr || !aSpriteFocusPtr)
    {
        throw std::runtime_error("UI::UI: aSpriteDefaultPtr NULL");
    }
    mSprites.push_back(aSpriteDefaultPtr);  // eStateDefault   = 0,
    mSprites.push_back(aSpriteDownPtr);     // eStateDown      = 1,
    mSprites.push_back(aSpriteFocusPtr);    // eStateFocus     = 2,
    mSprites.push_back(aSpriteDefaultPtr);  // eStateDisabled  = 3
}

UI::UI(const Sprite::Ptr&   aSpriteDefaultPtr,
       const Sprite::Ptr&   aSpriteDownPtr,
       const Sprite::Ptr&   aSpriteFocusPtr,
       const Sprite::Ptr&   aSpriteDisabledPtr,
       const Coord&         aCoord,
       const State          aState /* = eStateDefault */) :
    mCoord(aCoord),
    mZone(*this,
          aCoord.getX(), aCoord.getY(),
          aSpriteDefaultPtr->getRect().getW(), aSpriteDefaultPtr->getRect().getH()),
    mState(aState)
{
    if (!aSpriteDefaultPtr || !aSpriteDownPtr || !aSpriteFocusPtr || !aSpriteDisabledPtr)
    {
        throw std::runtime_error("UI::UI: aSpriteDefaultPtr NULL");
    }
    mSprites.push_back(aSpriteDefaultPtr);  // eStateDefault   = 0,
    mSprites.push_back(aSpriteDownPtr);     // eStateDown      = 1,
    mSprites.push_back(aSpriteFocusPtr);    // eStateFocus     = 2,
    mSprites.push_back(aSpriteDisabledPtr); // eStateDisabled  = 3
}

UI::~UI(void)
{
}


void UI::onOver(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UI::onOver(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UI::onOut (bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UI::onOut(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UI::onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UI::onDrag(aX=" << aX << ", aY="  << aY << ", abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UI::onDrop(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UI::onDrop(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

void UI::onClic(bool& abAlreadyConsumed)
{
    if (false == abAlreadyConsumed)
    {
        std::cout << "UI::onClic(abAlreadyConsumed=" << abAlreadyConsumed << ")" << std::endl;
        abAlreadyConsumed = true;
    }
    else
    {
        std::cout << "abAlreadyConsumed" << std::endl;
    }
}

