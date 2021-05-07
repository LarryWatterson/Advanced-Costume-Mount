// aratın

		case ITEM_POLYMORPH:
			return ItemProcess_Polymorph(item);

		case ITEM_QUEST:

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (GetWear(WEAR_COSTUME_MOUNT))
		{
			if (item->GetVnum() == 50051 || item->GetVnum() == 50052 || item->GetVnum() == 50053)
			{
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("YOU_CANNOT_USE_THIS_WHILE_RIDING"));
				return false;
			}
		}
#endif

// aratın

			(ITEM_UNIQUE == item->GetType() && UNIQUE_SPECIAL_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))
			|| (ITEM_UNIQUE == item->GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))

// değiştirin

			(ITEM_UNIQUE == item->GetType() && UNIQUE_SPECIAL_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))
			|| (ITEM_UNIQUE == item->GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			|| (ITEM_COSTUME == item->GetType() && COSTUME_MOUNT == item->GetSubType())
#endif

// aratın

			case POINT_COSTUME_ATTR_BONUS:
				{
					static BYTE abSlot[] = { WEAR_COSTUME_BODY, WEAR_COSTUME_HAIR

// wear içine ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
					WEAR_COSTUME_MOUNT,
#endif

// aratın

	{
		LPITEM u = GetWear(WEAR_UNIQUE2);

		if (u && u->GetVnum() == dwItemVnum)
			return true;
	}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	{
		LPITEM u = GetWear(WEAR_COSTUME_MOUNT);
		if (u && u->GetVnum() == dwItemVnum)
			return true;
	}
#endif

// aratın

	{
		LPITEM u = GetWear(WEAR_UNIQUE2);

		if (u && u->GetSpecialGroup() == (int) dwGroupVnum)
			return true;
	}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	{
		LPITEM u = GetWear(WEAR_COSTUME_MOUNT);
		if (u && u->GetSpecialGroup() == (int)dwGroupVnum)
			return true;
	}
#endif

// aratın

	LPITEM Unique1 = GetWear(WEAR_UNIQUE1);
	LPITEM Unique2 = GetWear(WEAR_UNIQUE2);

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	LPITEM MountCostume = GetWear(WEAR_COSTUME_MOUNT);
#endif

// aratın

	if( NULL != Unique2 )
	{
		if( UNIQUE_GROUP_SPECIAL_RIDE == Unique2->GetSpecialGroup() )
		{
			return UnequipItem(Unique2);
		}
	}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (MountCostume)
		return UnequipItem(MountCostume);
#endif

// aratın

							case 70201

// üstüne ekleyin
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
							case 91001:
							{
								LPITEM item2 = GetInventoryItem(wDestCell);
//Engellemeler
								if (!IsValidItemPosition(DestCell) || !(item2 = GetItem(DestCell)))
									return false;

								if (item2->IsExchanging() || item2->IsEquipped()) // her ihtimale karsi :)
									return false;

								if (GetExchange() || IsOpenSafebox() || GetShopOwner() || GetOfflineShopOwner())
									return false;

								if (item2->GetSocket(2) >= 15)
								{
									ChatPacket(CHAT_TYPE_INFO, LC_TEXT("binekmaxseviye"));
									return false;
								}
//Engellemeler bitis
								const DWORD binekEvrimItem[] = {50067, 50068};
								auto gerekliOlan = (item2->GetSocket(2)+1) * 5;
								auto type = item2->GetAttributeType(0);
								auto value = item2->GetAttributeValue(0);

								if(item2->GetType() == ITEM_COSTUME && item2->GetSubType() == COSTUME_MOUNT)
								{

								for(int binekItem = 0; binekItem < 2; binekItem++)
								{
									if (CountSpecifyItem(binekEvrimItem[binekItem]) < gerekliOlan)
									{
										ChatPacket(CHAT_TYPE_INFO, LC_TEXT("binekitemiyok"));
										return false;
										break;
									}
								}

									item2->SetSocket(2,item2->GetSocket(2) + 1);
									item2->SetForceAttribute(0,type, value+1);
									item2->Save();
									ChatPacket(CHAT_TYPE_INFO, LC_TEXT("binek_gelisti"));
									for (int i = 0; i < 2; i++){
										RemoveSpecifyItem(binekEvrimItem[i], gerekliOlan);
									}
									item->SetCount(item->GetCount() - 1);
								}
							}
						return true;
							break;

							case 91012: // sertrifika vnum
							{
								LPITEM item2 = GetInventoryItem(wDestCell);
//Engellemeler
								if (!IsValidItemPosition(DestCell) || !(item2 = GetItem(DestCell)))
									return false;

								if (item2->IsExchanging() || item2->IsEquipped()) // her ihtimale karsi :)
									return false;

								if (GetExchange() || IsOpenSafebox() || GetShopOwner() || GetOfflineShopOwner())
									return false;
//Engellemeler bitis
								int graphic = item->GetValue(0);
								MountGraphic(graphic, item2);
								item->SetCount(item->GetCount()-1);
							}
							break;
#endif