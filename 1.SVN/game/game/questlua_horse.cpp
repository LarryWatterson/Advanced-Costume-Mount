// aratın

	int horse_is_riding(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (ch->IsRidingMount())
			return 0;
		if (ch->GetMapIndex() == 113)
			return 0;
#endif

// aratın

	int horse_is_summon(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (ch->IsRidingMount())
			return 0;
		if (ch->GetMapIndex() == 113)
			return 0;
#endif
