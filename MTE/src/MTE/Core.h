#pragma once

#ifdef MTE_PLATFORM_WINDOWS
	#ifdef MTE_BUILD_DLL
		#define MTE_API __declspec(dllexport)
	#else
		#define MTE_API __declspec(dllimport)
	#endif
#else
	#error MTE only supports Windows!
#endif

#ifdef MTE_ENABLE_ASSERTS
	#define MTE_ASSERT(x, ...) { if(!(x)) { MTE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MTE_CORE_ASSERT(x, ...) { if(!(x)) { MTE__CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MTE_ASSERT(x, ...)
	#define MTE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MTE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)