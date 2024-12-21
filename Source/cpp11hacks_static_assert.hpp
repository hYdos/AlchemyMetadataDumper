#pragma once

// extra level of indirection to so the line number is used,
// otherwise __LINE__ would be tokenized
#define __static_assertion_helper_concat_(a, b) a ## b
#define __static_assertion_helper_concat(a, b) __static_assertion_helper_concat_(a, b)
#define static_assert(condition, message) __cpp11hacks__::StaticAssertion<static_cast<bool>(condition)>::success_t __static_assertion_helper_concat(__internalassert, __LINE__);

namespace __cpp11hacks__
{
	template<bool>
	struct StaticAssertion;

	template<>
	struct StaticAssertion<true>
	{
		struct success_t{};
	};

	template<>
	struct StaticAssertion<false> { };
}