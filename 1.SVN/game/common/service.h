#ifndef __INC_SERVICE_H__
#define __INC_SERVICE_H__

#define _IMPROVED_PACKET_ENCRYPTION_
#define __PET_SYSTEM__
#define __UDP_BLOCK__
// #define URIEL_AC_VERIFY
#define ENABLE_SWITCHBOT
///----------------------------------------------SİSTEMLER-EKLENTİLER-------------------------------------------------------------///
//##################---LONCA_SISTEMLERI---##################//
#define ENABLE_LONCA_GECMIS_SYSTEM
#define ENABLE_LONCA_AKTIF_LIDER_SYSTEM
#define ENABLE_SAVAS_IZNI_SYSTEM
#define ENABLE_LONCA_TOPLANTISI
#define ENABLE_LONCA_ISTATISTIK
//##################---LONCA_SISTEMLERI---##################//
///------------------------------------------------------------------------------------------------------------///
//##################---HACK_FIXED---##################//
#define HAYALET_MOD_HILESI_FIX
#define TELEPORT_HILESI_LOG
#define KARAKTER_ISIM_HILESI_FIX
#define MADENCI_BOTU_HILESI_FIX
#define SU_OLMAYAN_YERDE_BALIK_TUTMA_HILESI_FIX
#define BLOKLU_YERLERDE_ATAK_YAPMA_HILESI_FIX
//##################---HACK_FIXED---##################//
///------------------------------------------------------------------------------------------------------------///
//##################---ÇevrimDışı-Pazar-SYSTEM---##################//
#define OFFLINE_SHOP
#define GIFT_SYSTEM
#define SHOP_TIME_REFRESH 1*60
#define SHOP_BLOCK_GAME99
#define SHOP_AUTO_CLOSE
#define SHOP_GM_PRIVILEGES GM_IMPLEMENTOR
//##################---ÇevrimDışı-Pazar-SYSTEM---##################//
///------------------------------------------------------------------------------------------------------------///
//##################---Meley-SYSTEM---##################//
#define __DUNGEON_FOR_GUILD__
#ifdef __DUNGEON_FOR_GUILD__
	#define __MELEY_LAIR_DUNGEON__
	#ifdef __MELEY_LAIR_DUNGEON__
		#define __LASER_EFFECT_ON_75HP__
		#define __LASER_EFFECT_ON_50HP__
	#endif
#endif
//##################---Meley-SYSTEM---##################//
///------------------------------------------------------------------------------------------------------------///
//##################---Jotun-SYSTEM---##################//
#define __VERSION_162__
#ifdef __VERSION_162__
	#define HEALING_SKILL_VNUM 265
#endif
//##################---Jotun-SYSTEM---##################//
///------------------------------------------------------------------------------------------------------------///
#endif

//##################---Costume-SYSTEM---##################//
#define __WEAPON_COSTUME_SYSTEM__ 
#define __MOUNT_SYSTEM__
#define WJ_EXTENDED_PET_SYSTEM
#define ENABLE_BEVIS_SASH_SYSTEM
#define ENABLE_AURA_SYSTEM
//##################---Costume-SYSTEM---##################//
///------------------------------------------------------------------------------------------------------------///

//##################---Yayıncı-SYSTEM---##################//
#define ENABLE_YOUTUBE_SYSTEM
#ifdef ENABLE_YOUTUBE_SYSTEM
	#define ENABLE_YOUTUBER_TAG_SYSTEM
#endif

#define ENABLE_TWITCH_SYSTEM
#ifdef ENABLE_TWITCH_SYSTEM
	#define ENABLE_TWITCHER_TAG_SYSTEM
#endif
//##################---Yayıncı-SYSTEM---##################//
///------------------------------------------------------------------------------------------------------------///

//##################---OX-SYSTEM---##################//
#define ENABLE_OX_GORUNMEZLIK
#define ENABLE_OX_CHAT_ENGEL
#define ENABLE_OX_SKILL_ENGEL
#define ENABLE_OX_BINEK_ENGEL
#define ENABLE_OX_AT_ENGEL
#define ENABLE_OX_PET_ENGEL
//##################---OX-SYSTEM---##################//
///------------------------------------------------------------------------------------------------------------///
#define ENABLE_LOCALIZATION_SYSTEM
#define __SEND_TARGET_INFO__
#define __ANTI_RESIST_MAGIC_BONUS__
#define NEW_PET_SYSTEM
// #define __HIGHLIGHT_SYSTEM__
#define __MS_BUG_WITH_MAPS__
#define __VIEW_TARGET_PLAYER_HP__
#define __VIEW_TARGET_DECIMAL_HP__
#define ENABLE_YMIR_AFFECT_FIX
#define ENABLE_NEW_AFFECT_POTION
#define OKEY_CARD_SYSTEM
#define ITEM_SILME_SISTEMI
#define __7AND8TH_SKILLS__
#define __WOLFMAN_CHARACTER__
#define __BOSS_SECURITY__
#define ENABLE_2TH_SHOPEX_SYSTEM
#define WJ_SHOW_STROKE_INFO
#define ENABLE_CHEQUE_SYSTEM
#define ENABLE_SOULBIND_SYSTEM
#define __COSTUME_ATTR_SYSTEM__
#define __ATTR_TRANSFER_SYSTEM__
#define WJ_ENABLE_TRADABLE_ICON
#define WJ_SECURITY_SYSTEM
#define ENABLE_CUBE_RENEWAL
#define ENABLE_MESSENGER_BLOCK
#define WJ_CHANGELOOK_SYSTEM
#define ENABLE_DICE_SYSTEM
#define ENABLE_SPECIAL_STORAGE
#define ENABLE_MARKET_ARAMA_SYSTEM
#define ENABLE_SOLD_ITEM_SYSTEM
#define ENABLE_SHOP_SEEN
#define ENABLE_UZAK_MARKET_2_SYSTEM
#define ENABLE_GUVENLI_PC
#define ENABLE_HARDWARE_BAN
#define ENABLE_ITEM_KILITLEME_SYSTEM
#define ENABLE_HIZLI_RUHTASI_SYSTEM
#define ENABLE_HIZLI_BK_SYSTEM
#define ENABLE_SUPPORT_SYSTEM
#define ENABLE_SHOW_CHEST_DROP
#define ENABLE_MOUNT_COSTUME_SYSTEM			Edited by LWT
#define DISABLE_STOP_RIDING_WHEN_DIE
#define ENABLE_TRADE_CHAT
#define ENABLE_LONCA_GERI_SAYIM
//#define ENABLE_FEATURES_REFINE_SYSTEM
#define ENABLE_CAPTCHA_SYSTEM
#define ENABLE_BIYOLOG_SYSTEMS
#define ENABLE_BOSS_SIRALAMASI_SYSTEM
#define ENABLE_BECERI_SEC_SYSTEM
#define ENABLE_BK_TAKAS_SYSTEM
#define ENABLE_MAINTENANCE_SYSTEM
#define ENABLE_REBIRT_SYSTEM
#define ENABLE_ELEMENT_TARGET
#define ENABLE_ELEMENT_NEW_BONUSES
#define ENABLE_ELEMENT_SLOT
#define ENABLE_ISYAN_ENGEL
#define ENABLE_SHOW_MOB_INFO
#define ENABLE_PORT_SECURITY
#define ENABLE_MALL_BOX_SYSTEM
#define USE_TRANSMUTATION_SYSTEM_MAILBOX
#define USE_WON_SYSTEM_MAILBOX
#define __DEFENSE_WAVE__
#define __DUNGEON_INFO_SYSTEM__
#define __ENABLE_SHOP_DECORATION_SYSTEM__
#define	ENABLE_LOG_SYSTEM_DISABLE	
//#define ENABLE_SPIRIT_SYSTEM
#define ENABLE_BEVIS_BOSS_TRACKING_SYSTEM
#define ENABLE_SURGUN_MAGRASI_KORUMA
#define ENABLE_PET_ATTR_DETERMINE
#define ENABLE_GEM_SYSTEM
#define ENABLE_BOSS_GEM_SYSTEM
#define ENABLE_ALIGN_RENEWAL
#define ENABLE_CHEQUE_COUPON_SYSTEM
#define ENABLE_DS_GRADE_MYTH
#define ENABLE_PERMA_SET
#define USE_ACCE_SYSTEM_MAILBOX
#define ENABLE_GIVE_BASIC_ITEMS
#define ENABLE_ZODIAC_TEMPLE_SYSTEM
#ifdef ENABLE_ZODIAC_TEMPLE_SYSTEM
	#define ENABLE_ZODIAC_TEMPLE_CHAT
#endif
#define ENABLE_PICK_MOTION
#ifdef ENABLE_ITEMINE_WS_SYSTEM
	#define ENABLE_ITEMINE_WS_VECTOR
#endif
#define ENABLE_COSTUME_HIDE_SYSTEM
#define S_SKILL
#define THANOS_GLOVE
#define PARTI_SAVASI
#define ENABLE_BUY_WITH_ITEM																												// Shop Item selling by configurable item vnum
#define ENABLE_ITEM_SOUL_SYSTEM																												// Like GF Item Soul System
#define ENABLE_PLUS_SCROLL