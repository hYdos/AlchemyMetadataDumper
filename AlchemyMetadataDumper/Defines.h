#pragma once

#if TARGET_PS3 | TARGET_GC | TARGET_WII | TARGET_XBOX360 | TARGET_CAFE
#define TARGET_PPC 1
#else
#error "unimplemented architecture"
#endif // TARGET_PS3 | TARGET_GC | TARGET_WII | TARGET_XBOX360 | TARGET_CAFE