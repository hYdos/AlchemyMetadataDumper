#pragma once

#if __cplusplus < 201103L
#define nullptr (reinterpret_cast<void*>(0))

#include "cpp11hacks_static_assert.hpp"
#endif // __cplusplus < 201103L

#if TARGET_PS3
#include <sys/timer.h>
inline void sleep(usecond_t time)
{
	sys_timer_usleep(time * 1000);
}
#endif // TARGET_PS3

#if !defined(offsetof)
#define offsetof(type, member) (reinterpret_cast<size_t>(&(reinterpret_cast<type*>(0)->member)))
#endif // !defined(offsetof)