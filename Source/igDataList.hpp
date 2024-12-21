#pragma once

#include "igContainer.hpp"
#include "igMemory.hpp"

namespace Core
{
	template<typename T>
	class igTDataList : public igContainer
	{
	public:
		unsigned int _count;
		unsigned int _capacity;
		igMemory<T> _data;

		inline T get(int index)
		{
			return _data.get(index);
		}
		inline void set(int index, T value)
		{
			_data.set(index, value);
		}
	};
}