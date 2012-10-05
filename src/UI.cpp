#include <stdexcept>
#include <iostream>

#include "UI.h"
#include "Screen.h"
#include "Size.h"

/// RAII : garantie qu'un élément d'UI est toujours valide (dispose au moins d'un Sprite)
UI::UI(const Coord&         aCoord,
       const Size&          aSize,
       const Sprite::Ptr&   aSpriteDefaultPtr,
       const Sprite::Ptr&   aSpriteDownPtr,
       const Sprite::Ptr&   aSpriteFocusPtr,
       const Sprite::Ptr&   aSpriteDisabledPtr,
       const Sprite::Ptr&   aSpriteDragPtr) :
    mSprites(),
    mDrag(aSpriteDragPtr),
    mCoord(aCoord),
    mZone(*this,
          aCoord.getX(), aCoord.getY(),
          aSize.getW(), aSize.getH()),
    mState(eStateDefault)
{
    if (!aSpriteDefaultPtr || !aSpriteDownPtr || !aSpriteFocusPtr || !aSpriteDisabledPtr || !aSpriteDragPtr)
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

void UI::show(Screen& aScreen)
{
    aScreen.blit(*mSprites[mState], mCoord);
    mDrag.show(aScreen);
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
        mDrag.getCoord().set(aX,aY);
        mDrag.setVisible(true);
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
        mDrag.setVisible(false);
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
