// aratın

	{
		if (IsHorseRiding())
		{
			StopRiding();
		}
		else if (GetMountVnum())
		{
			RemoveAffect(AFFECT_MOUNT_BONUS);
			m_dwMountVnum = 0;
			UnEquipSpecialRideUniqueItem();

			UpdatePacket();
		}
	}

// koşulu komple değiştirin

#ifndef DISABLE_STOP_RIDING_WHEN_DIE
	{
		if (IsHorseRiding())
		{
			StopRiding();
		}
		else if (GetMountVnum())
		{
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM//olunce binek kaybolma fix
			RemoveAffect(AFFECT_MOUNT);
#endif
			RemoveAffect(AFFECT_MOUNT_BONUS);
			m_dwMountVnum = 0;
			UnEquipSpecialRideUniqueItem();

			UpdatePacket();
		}
	}
#endif