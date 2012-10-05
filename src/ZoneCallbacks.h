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

protected:
    virtual ~IZoneCallbacks(void) {};

private:
    virtual void onOver(bool& abAlreadyConsumed) = 0;
    virtual void onOut (bool& abAlreadyConsumed) = 0;
    virtual void onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed) = 0;
    virtual void onDrop(bool& abAlreadyConsumed) = 0;
    virtual void onClic(bool& abAlreadyConsumed) = 0;
};
