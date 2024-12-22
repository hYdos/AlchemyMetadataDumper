#pragma once

#include "Games.h"

namespace Core
{
	class igArkCore;
}

// I'm not the biggest fan of this
// TODO: Jasleen wants to move these into Game_Version_Addresses.cpp

// PS3
#if TARGET_PS3 && TARGET_GAME == SKYSC_01_06_00
#define ArkCore (*((Core::igArkCore**)0x01AEF084))
#define ArkCoreMetaFieldList (*(Core::igTVector<Core::igMetaField*>**)0x01AEF108)
#elif TARGET_PS3 && TARGET_GAME == SKYIM_01_01_00
#define ArkCore (*((Core::igArkCore**)0x01C68F6C))
#define ArkCoreMetaFieldList (*(Core::igTVector<Core::igMetaField*>**)0x01C68FF0)
#endif

// WIIU
#if TARGET_CAFE && TARGET_GAME == SKYSC_01_06_00
#define ArkCore (*((Core::igArkCore**)0x10516ba0))
#define ArkCoreMetaFieldList (*(Core::igTVector<Core::igMetaField*>**)0x10516be0)
#endif