#include "ZoneManager.h"

ZoneManager::ZoneManager(void)
{
}

ZoneManager::~ZoneManager(void)
{
}

void ZoneManager::onMouseMotion(const unsigned int aX, const unsigned int aY, const bool abIsDown)
{
    Zone::List::iterator    iZone;
    bool                    abAlreadyConsumed = false;

    // Notifie récursivement l'arborescence des #Zone
    for (iZone  = mZoneList.begin();
         iZone != mZoneList.end();
         iZone++)
    {
        iZone->onMouseMotion(aX, aY, abIsDown, abAlreadyConsumed);
    }
}

void ZoneManager::onMouseEvent (const unsigned int aX, const unsigned int aY, const bool abIsDown)
{
    Zone::List::iterator    iZone;
    bool                    abAlreadyConsumed = false;

    // Notifie récursivement l'arborescence des #Zone
    for (iZone  = mZoneList.begin();
         iZone != mZoneList.end();
         iZone++)
    {
        iZone->onMouseEvent(aX, aY, abIsDown, abAlreadyConsumed);
    }
}
