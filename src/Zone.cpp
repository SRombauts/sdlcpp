#include <iostream>
#include "Zone.h"

Zone::Zone(const unsigned int aX,
           const unsigned int aY,
           const unsigned int aW,
           const unsigned int aH) :
    mX(aX),
    mY(aY),
    mX2(aX + aW),
    mY2(aY + aH),
    mbIsMouseOver(false)
{
}

Zone::~Zone(void)
{
}

bool Zone::isOver(const unsigned int aX, const unsigned int aY) const
{
    bool bRet;

    bRet = (   (aX >= mX) && (aX <= mX2)
            && (aY >= mY) && (aY <= mY2) );
    //std::cout << "(aX=" << aX << ", aY=" << aY << ", mX=" << mX << ", mY=" << mY << ", mX2=" << mX2 << ", mY2=" << mY2 << ")=" << bRet << std::endl;

    return bRet;
}

bool Zone::updateMousePosition(const unsigned int aX, const unsigned int aY)
{
    bool bRet;

    // La souris est-elle au dessus de la zone ?
    bRet = isOver(aX, aY);
    if (   (true  == bRet)
        && (false == mbIsMouseOver))
    {
        // La souris vient d'entrer au dessus de la zone
        //std::cout << "Zone::UpdateMousePosition: onHoover(true)" << std::endl;
        this->onOver(true);
    }
    else if (   (false == bRet)
             && (true  == mbIsMouseOver))
    {
        // La souris vient de sortir de la zone
        //std::cout << "Zone::UpdateMousePosition: onHoover(false)" << std::endl;
        this->onOver(false);
    }
    // Mémorise l'état de la souris
    mbIsMouseOver = bRet;

    return bRet;
}
