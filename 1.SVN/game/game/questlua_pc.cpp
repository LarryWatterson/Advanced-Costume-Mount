/// aratın

	int pc_get_special_ride_vnum(lua_State* L)
	{
		LPCHARACTER pChar = CQuestManager::instance().GetCurrentCharacterPtr();

		if (NULL != pChar)
		{
			LPITEM Unique1 = pChar->GetWear(WEAR_UNIQUE1);
			LPITEM Unique2 = pChar->GetWear(WEAR_UNIQUE2);

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			LPITEM MountCostume = pChar->GetWear(WEAR_COSTUME_MOUNT);
#endif

// aratın

			if (NULL != Unique2)
			{
				if (UNIQUE_GROUP_SPECIAL_RIDE == Unique2->GetSpecialGroup())
				{
					lua_pushnumber(L, Unique2->GetVnum());
					lua_pushnumber(L, Unique2->GetSocket(2));
					return 2;
				}
			}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			if (MountCostume)
			{
				lua_pushnumber(L, MountCostume->GetVnum());
				lua_pushnumber(L, MountCostume->GetSocket(0)); // @fixme152 (2->0)
				return 2;
			}
#endif

// aratın

	void RegisterPCFunctionTable()

// üstüne ekleyin
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	int pc_binekver(lua_State* L)
	{

		if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2))
			return 0;

		BYTE valueType = (BYTE)lua_tonumber(L, 1);
		int graphic = (int)lua_tonumber(L, 2);

		LPITEM item = ITEM_MANAGER::instance().CreateItem(91000);
		//int graphic = 20209;
		int deger = 1;
		if (NULL == item)
		{
			lua_pushboolean(L, false);
			return 1;
		}

		const LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		int iEmptyCell = ch->GetEmptyInventory(item->GetSize());

		if (-1 == iEmptyCell)
		{
			M2_DESTROY_ITEM(item);
			lua_pushboolean(L, false);
			return 1;
		}

		switch(valueType)
		{
			case 1:
				item->AddAttribute(APPLY_ATTBONUS_HUMAN,deger);
				item->SetSocket(2, 1);
				item->SetSocket(3, graphic);
			break;
			case 2:
				item->AddAttribute(APPLY_ATTBONUS_MONSTER,deger);
				item->SetSocket(2, 1);
				item->SetSocket(3, graphic);
			break;
			case 3:
				item->AddAttribute(APPLY_ATTBONUS_STONE,deger);
				item->SetSocket(2, 1);
				item->SetSocket(3, graphic);
			break;
			case 4:
				item->AddAttribute(APPLY_EXP_DOUBLE_BONUS,deger);
				item->SetSocket(2, 1);
				item->SetSocket(3, graphic);
			break;
		default:
			ch->ChatPacket(CHAT_TYPE_INFO, "vazgec kanka manyak olursun");
			break;
		}

		item->AddToCharacter(ch, TItemPos(INVENTORY, iEmptyCell));
	}
#endif

// aratın

			{ NULL,			NULL			}

// üstüne ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			{ "binek_ver",			pc_binekver	},
#endif
