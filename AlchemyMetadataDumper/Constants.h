#pragma once

#include "Games.h"

namespace Core
{
	class igArkCore;
}

// I'm not the biggest fan of this

#if TARGET_PS3 && TARGET_GAME == SKYSC_01_06_00
#define ArkCore (*((Core::igArkCore**)0x01AEF084))
#define ArkCoreMetaFieldList (*(Core::igTVector<Core::igMetaField*>**)0x01AEF108)
#elif TARGET_PS3 && TARGET_GAME == SKYIM_01_01_00
#define ArkCore (*((Core::igArkCore**)0x01C68F6C))
#define ArkCoreMetaFieldList (*(Core::igTVector<Core::igMetaField*>**)0x01C68FF0)
#endif