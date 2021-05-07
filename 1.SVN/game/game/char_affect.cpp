// aratın

	if ( CArenaManager::instance().IsArenaMap(GetMapIndex()) == true )
	{
		RemoveGoodAffect();
	}

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	RemoveAffect(AFFECT_MOUNT);
	RemoveAffect(AFFECT_MOUNT_BONUS);
#endif