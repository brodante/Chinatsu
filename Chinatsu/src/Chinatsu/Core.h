#pragma once

#ifdef CN_PLATFORM_WINDOWS
	#ifdef CN_BUILD_DLL
		#define CHINATSU_API __declspec(dllexport)
	#else
		#define CHINATSU_API __declspec(dllimport)
	#endif
#else
	#error Chinatsu only supports Windows!
#endif