#pragma once

#include <stdint.h>

#include "AddressMacros.h"
#include "Constants.h"

#ifdef __PS3__
struct opd_s
{
	uint32_t sub;
	uint32_t toc;
};
#endif // __PS3__

namespace __stubs
{
	DeclareMethod(int, __sprintf, char* buffer, const char* fmt, ...);
}

namespace Core
{
	class igMetaObject;
	class igMetaEnum;
	class igArkCore;

	DeclareMethod(bool, igMetaObject_isOfType, const igMetaObject* thisMeta, const igMetaObject* otherMeta);

	DeclareMethod(igMetaObject*, igArkCore_getObjectMeta, igArkCore* thisPtr, const char* name);
}

DeclareMethod(int, _igReportPrintf, const char* fmt, ...);