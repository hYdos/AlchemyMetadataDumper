#pragma once

#include "igMemory.hpp"
#include <stddef.h>

namespace Core
{
	template<typename T>
	struct igTVector
	{
		size_t _count;
		igMemory<T> _data;

		inline T get(int index) const
		{
			return _data.get(index);
		}
		inline void set(int index, T value)
		{
			_data.set(index, value);
		}
	};
}