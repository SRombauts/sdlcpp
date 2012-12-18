#include "ZoneManager.h"

ZoneManager::ZoneManager(void) :
    mMenuList(),
    mUiList(),
    mTowerList()
{
}

ZoneManager::~ZoneManager(void)
{
}

void ZoneManager::onMouseMotion(const unsigned int aX, const unsigned int aY, const bool abIsDown)
{
    Zone::List::iterator    iZone;
    bool                    abAlreadyConsumed = false;

    // Notifie chaque liste de zones, par priorité décroissante
    for (iZone  = mMenuList.begin();
         iZone != mMenuList.end();
         iZone++)
    {
        iZone->onMouseMotion(aX, aY, abIsDown, abAlreadyConsumed);
    }
    for (iZone  = mUiList.begin();
         iZone != mUiList.end();
         iZone++)
    {
        iZone->onMouseMotion(aX, aY, abIsDown, abAlreadyConsumed);
    }
    for (iZone  = mTowerList.begin();
         iZone != mTowerList.end();
         iZone++)
    {
        iZone->onMouseMotion(aX, aY, abIsDown, abAlreadyConsumed);
    }
}

void ZoneManager::onMouseEvent (const unsigned int aX, const unsigned int aY, const bool abIsDown)
{
    Zone::List::iterator    iZone;
    bool                    abAlreadyConsumed = false;

    // Notifie chaque liste de zones, par priorité décroissante
    for (iZone  = mMenuList.begin();
         iZone != mMenuList.end();
         iZone++)
    {
        iZone->onMouseEvent(aX, aY, abIsDown, abAlreadyConsumed);
    }
    for (iZone  = mUiList.begin();
         iZone != mUiList.end();
         iZone++)
    {
        iZone->onMouseEvent(aX, aY, abIsDown, abAlreadyConsumed);
    }
    for (iZone  = mTowerList.begin();
         iZone != mTowerList.end();
         iZone++)
    {
        iZone->onMouseEvent(aX, aY, abIsDown, abAlreadyConsumed);
    }
}
