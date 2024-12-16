#pragma once

#include "igDataList.hpp"

namespace Core
{
	template<typename T>
	class igTObjectList : public igTDataList<T*>
	{
		DefineVirtualFunc_0(0x1C, igMetaObject*, getElementType);
	};
	typedef igTObjectList<igObject> igObjectList;
}