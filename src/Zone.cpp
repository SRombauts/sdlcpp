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
    mbIsMouseInside(false)
{
}

Zone::~Zone(void)
{
}

bool Zone::isInside(const unsigned int aX, const unsigned int aY) const
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
    bRet = isInside(aX, aY);
    if (   (true  == bRet)
        && (false == mbIsMouseInside))
    {
        // La souris vient d'entrer au dessus de la zone
        // TODO SRombauts : onHoover(true)
        std::cout << "Zone::UpdateMousePosition: onHoover(true)" << std::endl;
    }
    else if (   (false == bRet)
             && (true  == mbIsMouseInside))
    {
        // La souris vient de sortir de la zone
        // TODO SRombauts : onHoover(false)
        std::cout << "Zone::UpdateMousePosition: onHoover(false)" << std::endl;
    }
    // Mémorise l'état de la souris
    mbIsMouseInside = bRet;

    return bRet;
}
