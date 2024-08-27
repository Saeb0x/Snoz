#pragma once

#ifdef SZ_PLATFORM_WINDOWS
	#ifdef SZ_BUILD_DLL
		#define SZ_API __declspec(dllexport)
	#else
		#define SZ_API __declspec(dllimport)
	#endif
#else
	#error Snoz only supports Windows for now!
#endif