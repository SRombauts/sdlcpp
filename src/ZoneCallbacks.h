#pragma once

/**
 * @brief Interface décrivant les callbacks d'une Zone.
 *
 * @author 2012/09/29 SRombauts
*/
class IZoneCallbacks
{
protected:
    virtual void onOver(const bool abIsOver) = 0;
};
