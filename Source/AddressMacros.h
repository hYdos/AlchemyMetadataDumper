#pragma once

#if TARGET_PS3
#include "TocDefinition.h"
#endif // TARGET_PS3

#define DeclareMethod(ret, name, ...) \
extern ret(*name)(__VA_ARGS__)

#if TARGET_PS3

// PS3 functions work with a TOC pointer

#define DefineMethodWithToc(address, toc, ret, name, ...) \
opd_s _##name = { address, toc }; \
ret(*name)(__VA_ARGS__) = (ret(*)(__VA_ARGS__))&_##name

#define DefineMethod(address, ret, name, ...) DefineMethodWithToc(address, TOC_BASE, ret, name, __VA_ARGS__)

#endif // TARGET_PS3