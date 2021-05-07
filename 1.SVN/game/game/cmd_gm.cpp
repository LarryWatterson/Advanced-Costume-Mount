// aratın

ACMD(do_horse_summon)
{

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ch->IsRidingMount())
		return;
#endif