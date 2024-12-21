#pragma once

#include "__internalObjectBase.hpp"

namespace Core
{
	class igMemoryPool;
	class igDataObjectReader;
	class igDataWriterStream;
	class igObjectDirectory;

	class igObject : public __internalObjectBase
	{
	public:
		DefineVirtualFunc_1( 1, bool, isAlikeDeep, igObject*, other)
		DefineVirtualFunc_1( 2, void, userAllocateFields, bool, unk)
		DefineVirtualFunc_0( 3, void, userDeallocateFields)
		DefineVirtualFunc_1( 4, void, userCopyDeep, igObject*, other)
		DefineVirtualFunc_1( 5, void, userCopyShallow, igObject*, other)
		DefineVirtualFunc_1( 6, void, userInstantiate, bool, unk)
		DefineVirtualFunc_0( 7, void, userRelease)
		DefineVirtualFunc_1( 8, void, userResetFields, bool, unk)
		DefineVirtualFunc_0( 9, void, preWrite)
		DefineVirtualFunc_0(10, void, postWrite)
		DefineVirtualFunc_0(11, void, preFileWrite)
		DefineVirtualFunc_0(12, void, postFileWrite)
		DefineVirtualFunc_0(13, void, postRead)
		DefineVirtualFunc_0(14, void, postFileRead)
		DefineVirtualFunc_1(15, void, createDataInheritanceInfo, igMemoryPool*, pool)
		DefineVirtualFunc_1(16, void, readFromStream, igDataObjectReader*, reader)
		DefineVirtualFunc_1(17, void, readItemFromStream, igDataObjectReader*, reader)
		DefineVirtualFunc_2(18, void, writeItemToStream, igDataWriterStream*, stream, igObjectDirectory*, directory)
		DefineVirtualFunc_0(19, void, clean)
	};
}
