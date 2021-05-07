// aratın

		if (m_vec_prototype[i].bType == ITEM_QUEST || IS_SET(m_vec_prototype[i].dwFlags, ITEM_FLAG_QUEST_USE | ITEM_FLAG_QUEST_USE_MULTIPLE)

// değiştirin

		if (m_vec_prototype[i].bType == ITEM_QUEST || IS_SET(m_vec_prototype[i].dwFlags, ITEM_FLAG_QUEST_USE | ITEM_FLAG_QUEST_USE_MULTIPLE)
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			|| (m_vec_prototype[i].bType == ITEM_COSTUME && m_vec_prototype[i].bSubType == COSTUME_MOUNT)
#endif

			)

// aratın

	else if (item->GetType() == ITEM_UNIQUE)

//değiştirin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	else if (item->GetType() == ITEM_UNIQUE || (item->GetType() == ITEM_COSTUME && item->GetSubType() == COSTUME_MOUNT))
#else
	else if (item->GetType() == ITEM_UNIQUE)
#endif