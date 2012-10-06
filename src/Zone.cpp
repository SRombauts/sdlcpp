#include <iostream>
#include "Zone.h"
#include "ZoneCallbacks.h"

Zone::Zone(IZoneCallbacks&    aZoneCallbacks,
           const unsigned int aX,
           const unsigned int aY,
           const unsigned int aW,
           const unsigned int aH) :
    mZoneCallbacks(aZoneCallbacks),
    mX(aX),
    mY(aY),
    mW(aW),
    mH(aH),
    mX2(aX + aW),
    mY2(aY + aH),
    mbIsMouseOver(false),
    mbIsClicked(false),
    mbIsDraged(false),
    mbOnOverCalled(false),
    mZoneList()
{
}

Zone::~Zone(void)
{
}

void Zone::set(const unsigned int aX, const unsigned int aY)
{
    mX = aX;
    mY = aY;
    mX2 = aX + mW;
    mY2 = aY + mH;
}

bool Zone::isOver(const unsigned int aX, const unsigned int aY) const
{
    bool bRet;

    bRet = (   (aX >= mX) && (aX <= mX2)
            && (aY >= mY) && (aY <= mY2) );
    //std::cout << "(aX=" << aX << ", aY=" << aY << ", mX=" << mX << ", mY=" << mY << ", mX2=" << mX2 << ", mY2=" << mY2 << ")=" << bRet << std::endl;

    return bRet;
}

void Zone::onMouseMotion(const unsigned int aX, const unsigned int aY, const bool abIsDown, bool& abAlreadyConsumed)
{
    bool                    bIsOver;
    Zone::List::iterator    iZone;

    // Commence par mettre à jour récursivement l'arborescence des éventuelles zones filles
    for (iZone  = mZoneList.begin();
         iZone != mZoneList.end();
         iZone++)
    {
        iZone->onMouseMotion(aX, aY, abIsDown, abAlreadyConsumed);
    }

    // Puis teste si la souris est au dessus de la zone
    bIsOver = isOver(aX, aY);
//    if (bIsOver)
//        std::cout << "Zone::onMouseMotion: " << aX << ", " << aY << ", " << abIsDown << ", " << abAlreadyConsumed << std::endl;

    if (abIsDown)
    {
        if (mbIsClicked)
        {
            mZoneCallbacks.onDrag(aX, aY, abAlreadyConsumed);
            mbIsDraged = true;
        }
    }
    else
    {
        if (   (true  == bIsOver)
            && (false == mbIsMouseOver))
        {
            // La souris vient d'entrer au dessus de la zone
            mZoneCallbacks.onOver(abAlreadyConsumed);
            mbOnOverCalled = true;
        }
        else if (   (false == bIsOver)
                 && (true  == mbIsMouseOver))
        {
            if (mbOnOverCalled)
            {
                // La souris vient de sortir de la zone
                mZoneCallbacks.onOut(abAlreadyConsumed);
                mbOnOverCalled = false;
            }
        }
    }

    // Mémorise l'état de la souris
    mbIsMouseOver = bIsOver;
}

void Zone::onMouseEvent (const unsigned int aX, const unsigned int aY, const bool abIsDown, bool& abAlreadyConsumed)
{
    bool                    bIsOver;
    Zone::List::iterator    iZone;

    // Commence par mettre à jour récursivement l'arborescence des éventuelles zones filles
    for (iZone  = mZoneList.begin();
         iZone != mZoneList.end();
         iZone++)
    {
        iZone->onMouseEvent(aX, aY, abIsDown, abAlreadyConsumed);
    }

    if (mbIsDraged)
    {
        mZoneCallbacks.onDrop(abAlreadyConsumed);
        mbIsDraged = false;
        mbIsClicked = false;
    }
    else
    {
        // Puis teste si la souris est au dessus de la zone
        bIsOver = isOver(aX, aY);
//      if (bIsOver)
//          std::cout << "Zone::onMouseEvent: " << aX << ", " << aY << ", " << abIsDown << ", " << abAlreadyConsumed << std::endl;

        if (bIsOver)
        {
            if (mbOnOverCalled)
            {
                // Le clic souris provoque une "sortie" de la zone
                mZoneCallbacks.onOut(abAlreadyConsumed);
                mbOnOverCalled = false;
            }
            if (abIsDown)
            {
                mbIsClicked = true;
            }
            else
            {
                mZoneCallbacks.onClic(abAlreadyConsumed);
                mbIsClicked = false;
            }
        }
    }
}
