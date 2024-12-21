#pragma once

#include <stdint.h>

#include "Games.h"

#if TARGET_GAME == SKYSC_01_06_00
#define TOC_BASE 0x1AE9778
#elif TARGET_GAME == SKYIM_01_01_00
#define TOC_BASE 0x1C5EBF8
#endif