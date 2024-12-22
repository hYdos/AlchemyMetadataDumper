#pragma once

#include <stdint.h>

#include "Games.h"

#include "igHashTable.hpp"

namespace Core
{
	class igMetaObject;
	class igMetaEnum;

	class igArkCore
	{
	private:
#if TARGET_PS3 && TARGET_GAME >= SKYSC_01_00_00 && TARGET_GAME <= SKYIM_01_01_00
		uint8_t _unk00[0x24];
#elif TARGET_CAFE && TARGET_GAME >= SKYSC_01_00_00 && TARGET_GAME <= SKYIM_01_01_00
		uint8_t _unk00[0x24];
#else
#error "unsupported platform or game!"
#endif
	public:
		igTUHashTable<igMetaObject*, const char*>* _metaObjectHashTable;
		igTUHashTable<igMetaEnum*,   const char*>* _metaEnumHashTable;
	};
}