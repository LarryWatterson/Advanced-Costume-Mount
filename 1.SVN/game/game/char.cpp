//include içine ekleyin
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
#include "MountSystem.h"
#endif

// arat
	m_pointsInstant.iDragonSoulActiveDeck = -1;
	memset(&m_tvLastSyncTime, 0, sizeof(m_tvLastSyncTime));

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	m_mountSystem = 0;
	m_bIsMount = false;
	m_bMountCounter = 0;
#endif

// aratın

	if (m_pkDungeon) /burasıdır
	{
		SetDungeon(NULL);
	}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (m_mountSystem)
	{
		m_mountSystem->Destroy();
		delete m_mountSystem;
		m_mountSystem = 0;
	}
	if (GetMountVnum())
	{
		RemoveAffect(AFFECT_MOUNT);
		RemoveAffect(AFFECT_MOUNT_BONUS);//doğru
	}
#endif

// aratın

	CTargetManager::instance().Logout(GetPlayerID());

	MessengerManager::instance().Logout(GetName());

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (GetMountVnum())
	{
		RemoveAffect(AFFECT_MOUNT);
		RemoveAffect(AFFECT_MOUNT_BONUS);
	}
#endif

// aratın

	sys_log(0, "PLAYER_LOAD: %s PREMIUM %d %d, LOGGOFF_INTERVAL %u PTR: %p", t->name, m_aiPremiumTimes[0], m_aiPremiumTimes[1], t->logoff_interval, this);

	if (GetGMLevel() != GM_PLAYER)
	{
		LogManager::instance().CharLog(this, GetGMLevel(), "GM_LOGIN", "");
		sys_log(0, "GM_LOGIN(gmlevel=%d, name=%s(%d), pos=(%d, %d)", GetGMLevel(), GetName(), GetPlayerID(), GetX(), GetY());
	}


// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (m_mountSystem)
	{
		m_mountSystem->Destroy();
		delete m_mountSystem;
	}
	m_mountSystem = M2_NEW CMountSystem(this);
#endif

// aratın

		if (GetMountVnum())

// değiştirin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (GetMountVnum() && !GetWear(WEAR_COSTUME_MOUNT))
#else
		if (GetMountVnum())
#endif

// en alta ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
void CHARACTER::MountSummon(LPITEM mountItem)
{
	if (GetMapIndex() == 113)
		return;

	if (CWarMapManager::instance().IsWarMap(GetMapIndex()))
		return;

	CMountSystem* mountSystem = GetMountSystem();
	DWORD mobVnum = 0;

	if (!mountSystem || !mountItem)
		return;

	if (mountItem->GetSocket(3) != 0)
		mobVnum = mountItem->GetSocket(3);

	if (IsHorseRiding())
		StopRiding();

	if (GetHorse())
		HorseSummon(false);

	mountSystem->Summon(mobVnum, mountItem, false);
}

void CHARACTER::MountUnsummon(LPITEM mountItem)
{
	CMountSystem* mountSystem = GetMountSystem();
	DWORD mobVnum = 0;

	if (!mountSystem || !mountItem)
		return;

	if (mountItem->GetSocket(3) != 0)
		mobVnum = mountItem->GetSocket(3);

	if (GetMountVnum() == mobVnum)
		mountSystem->Unmount(mobVnum);

	mountSystem->Unsummon(mobVnum);
}

void CHARACTER::CheckMount()
{
	if (GetMapIndex() == 113)
		return;

	if (CWarMapManager::instance().IsWarMap(GetMapIndex()))
		return;

	CMountSystem* mountSystem = GetMountSystem();
	LPITEM mountItem = GetWear(WEAR_COSTUME_MOUNT);
	DWORD mobVnum = 0;

	if (!mountSystem || !mountItem)
		return;

	if (mountItem->GetSocket(3) != 0)
		mobVnum = mountItem->GetSocket(3);

	if (mountSystem->CountSummoned() == 0)
	{
		mountSystem->Summon(mobVnum, mountItem, false);
	}
}

bool CHARACTER::IsRidingMount()
{
	return (GetWear(WEAR_COSTUME_MOUNT) || FindAffect(AFFECT_MOUNT));
}

bool CHARACTER::MountGraphic(int graphic, LPITEM item) // by LWT
{
	if (item->GetType() == ITEM_COSTUME && item->GetSubType() == COSTUME_MOUNT)
	{
		item->SetSocket(3, graphic);
		item->Save();
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("binekhokrdsm"));
	}
	else{ChatPacket(CHAT_TYPE_INFO, "Manyak olursun kanka vazgec");}
			return true;
}

#endif

