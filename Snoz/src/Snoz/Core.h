#pragma once

#ifdef SZ_PLATFORM_WINDOWS
#if SZ_DYNAMIC_BUILD
	#ifdef SZ_BUILD_DLL
		#define SZ_API __declspec(dllexport)
	#else
		#define SZ_API __declspec(dllimport)
	#endif
#else
	#define SZ_API
#endif
#else
	#error Snoz only supports Windows for now!
#endif

#define SZ_ASSERT(x, ...) if(!(x)) {SZ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}