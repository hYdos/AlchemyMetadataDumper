#include "Games.h"

#if TARGET_GAME == SKYSC_01_06_00

#include "Addresses.h"
//
namespace __stubs
{
	DefineMethod(0x0123a23c, int, __sprintf, char* buffer, const char* fmt, ...);
}

namespace Core
{
	DefineMethod(0x00b4c448, bool, igMetaObject_isOfType, const igMetaObject* thisMeta, const igMetaObject* otherMeta);
	DefineMethod(0x00b41130, igMetaObject*, igArkCore_getObjectMeta, igArkCore* thisPtr,  const char* name);
}

DefineMethod(0x00b9b724, int, _igReportPrintf, const char* fmt, ...);

#endif // TARGET_GAME == SKYSC_01_06_00