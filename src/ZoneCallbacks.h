#pragma once

class Zone;

/**
 * @brief Interface décrivant les callbacks d'une #Zone.
 *
 * @author 2012/09/29 SRombauts
*/
class IZoneCallbacks
{
    friend class Zone;

private:
    virtual void onOver(const bool abIsOver, bool& abAlreadyConsumed) = 0;
};
