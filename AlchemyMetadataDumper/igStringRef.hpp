#pragma once

namespace Core
{
	struct igStringRef
	{
		const char* _value;
		operator const char*() const { return _value; }
		operator const char*() { return _value; }
	};
}