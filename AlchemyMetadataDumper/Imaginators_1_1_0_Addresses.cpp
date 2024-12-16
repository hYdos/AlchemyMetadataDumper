#include "Games.h"

#if TARGET_GAME == SKYIM_01_01_00

#include "Addresses.h"
//
namespace __stubs
{
	DefineMethod(0x013d0e88, int, __sprintf, char* buffer, const char* fmt, ...);
}

namespace Core
{
	DefineMethod(0x00cf7c54, bool, igMetaObject_isOfType, const igMetaObject* thisMeta, const igMetaObject* otherMeta);
	DefineMethod(0x00cecaf8, igMetaObject*, igArkCore_getObjectMeta, igArkCore* thisPtr,  const char* name);
}

DefineMethod(0x00d48084, int, _igReportPrintf, const char* fmt, ...);

#endif // TARGET_GAME == SKYIM_01_01_00