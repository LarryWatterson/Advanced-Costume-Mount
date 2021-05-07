// aratın

	PyModule_AddIntConstant(poModule, "COSTUME_SLOT_START",			c_Costume_Slot_Start);

// üstüne ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "COSTUME_TYPE_MOUNT", CItemData::COSTUME_MOUNT);
#endif

// aratın

	PyModule_AddIntConstant(poModule, "COSTUME_SLOT_END",			c_Costume_Slot_End);

// üstüne ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "COSTUME_SLOT_MOUNT", c_Costume_Slot_Mount);
#endif