// include'lere ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
#include "MountSystem.h"
#endif

// aratın (case SCMD_RESTART_HERE:)

					ch->ReviveInvisible(5);

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		ch->CheckMount();
#endif

// aratın

ACMD(do_unmount)
{

// hemen altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ch->GetWear(WEAR_COSTUME_MOUNT))
	{
		CMountSystem* mountSystem = ch->GetMountSystem();
		LPITEM mount = ch->GetWear(WEAR_COSTUME_MOUNT);
		DWORD mobVnum = 0;

		if (!mountSystem && !mount)
			return;
		if (mount->GetSocket(3) != 0)
			mobVnum = mount->GetSocket(3);

		if (ch->GetMountVnum())
		{
			if (mountSystem->CountSummoned() == 0)
			{
				mountSystem->Unmount(mobVnum);
			}
		}
		return;
	}
#endif

// aratın

ACMD(do_ride)

// komple değiştirin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
ACMD(do_ride)
{
	if (ch->IsDead() || ch->IsStun())
		return;
	if (ch->GetMapIndex() == 113)
		return;
	if (ch->IsPolymorphed()) {
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Dönüşmüş haldeyken bineğe binemezsin."));
		return;
	}
	if (ch->GetWear(WEAR_COSTUME_MOUNT))
	{
		CMountSystem* mountSystem = ch->GetMountSystem();
		LPITEM mount = ch->GetWear(WEAR_COSTUME_MOUNT);
		DWORD mobVnum = 0;
		if (!mountSystem && !mount)
			return;
		if (mount->GetSocket(3) != 0)
			mobVnum = mount->GetSocket(3);

		if (ch->GetMountVnum())
		{
			if (mountSystem->CountSummoned() == 0)
				mountSystem->Unmount(mobVnum);
		}
		else
		{
			if (mountSystem->CountSummoned() == 1)
				mountSystem->Mount(mobVnum, mount);
		}

		return;
	}
	if (ch->IsHorseRiding())
	{
		ch->StopRiding();
		return;
	}

	if (ch->GetHorse() != NULL)
	{
		ch->StartRiding();
		return;
	}

	for (BYTE i = 0; i < INVENTORY_MAX_NUM; ++i)
	{
		LPITEM item = ch->GetInventoryItem(i);
		if (NULL == item)
			continue;

		if (item->GetType() == ITEM_COSTUME && item->GetSubType() == COSTUME_MOUNT) {
			ch->UseItem(TItemPos(INVENTORY, i));
			return;
		}
	}

	ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("¸»À» ¸ÕÀú ¼ÒÈ¯ÇØÁÖ¼¼¿ä."));
}
#else
ACMD(do_ride)
{
	dev_log(LOG_DEB0, "[DO_RIDE] start");
	if (ch->IsDead() || ch->IsStun())
		return;

	{
		if (ch->IsHorseRiding())
		{
			dev_log(LOG_DEB0, "[DO_RIDE] stop riding");
			ch->StopRiding();
			return;
		}

		if (ch->GetMountVnum())
		{
			dev_log(LOG_DEB0, "[DO_RIDE] unmount");
			do_unmount(ch, NULL, 0, 0);
			return;
		}
	}

	{
		if (ch->GetHorse() != NULL)
		{
			dev_log(LOG_DEB0, "[DO_RIDE] start riding");
			ch->StartRiding();
			return;
		}

		for (BYTE i = 0; i < INVENTORY_MAX_NUM; ++i)
		{
			LPITEM item = ch->GetInventoryItem(i);
			if (NULL == item)
				continue;

			if (item->IsRideItem())
			{
				if (
					NULL == ch->GetWear(WEAR_UNIQUE1)
					|| NULL == ch->GetWear(WEAR_UNIQUE2)
					)
				{
					dev_log(LOG_DEB0, "[DO_RIDE] USE UNIQUE ITEM");
					//ch->EquipItem(item);
					ch->UseItem(TItemPos(INVENTORY, i));
					return;
				}
			}

			switch (item->GetVnum())
			{
			case 71114:
			case 71116:
			case 71118:
			case 71120:
				dev_log(LOG_DEB0, "[DO_RIDE] USE QUEST ITEM");
				ch->UseItem(TItemPos(INVENTORY, i));
				return;
			}

			// GF mantis #113524, 52001~52090 ¹ø Å»°Í
			if ((item->GetVnum() > 52000) && (item->GetVnum() < 52091)) {
				dev_log(LOG_DEB0, "[DO_RIDE] USE QUEST ITEM");
				ch->UseItem(TItemPos(INVENTORY, i));
				return;
			}
		}
	}

	ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("¸»À» ¸ÕÀú ¼ÒÈ¯ÇØÁÖ¼¼¿ä."));
}
#endif