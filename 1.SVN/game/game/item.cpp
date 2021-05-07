// aratın

		else if (GetSubType() == COSTUME_HAIR)
			return WEAR_COSTUME_HAIR;

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		else if (GetSubType() == COSTUME_MOUNT)
			return WEAR_COSTUME_MOUNT;
#endif
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		else if (GetSubType() == COSTUME_MOUNT && m_pOwner->IsDisabledMountSummonArea())//lonca savasinda binek engelleme
			return WEAR_COSTUME_MOUNT;
#endif

// aratın (hemen altında)

		if (ch->GetWear(WEAR_RING1))
			return WEAR_RING2;
		else
			return WEAR_RING1;

// değiştirin

#if !defined(ENABLE_MOUNT_COSTUME_SYSTEM) && !defined(ENABLE_ACCE_SYSTEM)
	else if (GetType() == ITEM_RING)
	{
		if (ch->GetWear(WEAR_RING1))
			return WEAR_RING2;
		else
			return WEAR_RING1;
	}
#else
	else if (GetType() == ITEM_RING)
	{
		if (GetVnum() == 91000)
			return WEAR_RING1;
		else
			return WEAR_RING2;
/*
		if (ch->GetWear(WEAR_RING1))
			return WEAR_RING2;
		else
			return WEAR_RING1;
*/
	}
#endif

// aratın

						if (p->aApplies[i].bType == APPLY_NONE)
							continue;

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
						if (IsMountItem())
							continue;
#endif

// aratın

				else if (GetSubType() == COSTUME_HAIR)
				{
					toSetPart = PART_HAIR;

					// ÄÚ½ºÃõ Çì¾î´Â shape°ªÀ» item protoÀÇ value3¿¡ ¼¼ÆÃÇÏµµ·Ï ÇÔ. Æ¯º°ÇÑ ÀÌÀ¯´Â ¾ø°í ±âÁ¸ °©¿Ê(ARMOR_BODY)ÀÇ shape°ªÀÌ ÇÁ·ÎÅäÀÇ value3¿¡ ÀÖ¾î¼­ Çì¾îµµ °°ÀÌ value3À¸·Î ÇÔ.
					// [NOTE] °©¿ÊÀº ¾ÆÀÌÅÛ vnumÀ» º¸³»°í Çì¾î´Â shape(value3)°ªÀ» º¸³»´Â ÀÌÀ¯´Â.. ±âÁ¸ ½Ã½ºÅÛÀÌ ±×·¸°Ô µÇ¾îÀÖÀ½...
					toSetValue = (true == bAdd) ? this->GetValue(3) : 0;
				}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		else if (GetSubType() == COSTUME_MOUNT)
		{
			// not need to do a thing in here
		}
#endif

// aratın

	ch->BuffOnAttr_AddBuffsFromItem(this);
	m_pOwner->ComputeBattlePoints();

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		ch->MountSummon(this);
#endif

// aratın

	if (this != m_pOwner->GetWear(GetCell() - INVENTORY_MAX_NUM))
	{
		sys_err("m_pOwner->GetWear() != this");
		return false;
	}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		m_pOwner->MountUnsummon(this);
#endif

// aratın

	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == GetSubType())
		return true;

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ITEM_COSTUME == GetType() && COSTUME_MOUNT == GetSubType())
		return true;
#endif

// aratın

bool CItem::IsRamadanRing()
{
	if (GetVnum() == UNIQUE_ITEM_RAMADAN_RING || GetVnum() == UNLIMITED_RAMADAN_RING) //LWT
		return true;
	return false;
}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
bool CItem::IsMountItem()
{
	if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_MOUNT)
		return true;
	return false;
}
#endif

// aratın

bool CItem::IsNewMountItem()

// fonksiyonu komple değiştirin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
bool CItem::IsNewMountItem()
{
	return (
		(ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_RIDE == GetSubType() && IS_SET(GetFlag(), ITEM_FLAG_QUEST_USE))
		|| (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == GetSubType() && IS_SET(GetFlag(), ITEM_FLAG_QUEST_USE))
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		|| (ITEM_COSTUME == GetType() && COSTUME_MOUNT == GetSubType())
#endif
		); // @fixme152
}
#else
bool CItem::IsNewMountItem()
{
	switch(GetVnum())
	{
		case 76000: case 76001: case 76002: case 76003:
		case 76004: case 76005: case 76006: case 76007:
		case 76008: case 76009: case 76010: case 76011:
		case 76012: case 76013: case 76014:
			return true;
	}
	return false;
}
#endif

