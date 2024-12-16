#pragma once

#include "igContainer.hpp"
#include "igMemory.hpp"

namespace Core
{
	template<typename T, typename U>
	class igTUHashTable : igContainer
	{
	public:
		igMemory<T> _values;
		igMemory<U> _keys;
		int _hashItemCount;
		bool _autoRehash;
		float _loadFactor;
	};
}