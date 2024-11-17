#pragma once

#ifdef CH_PLATFORM_WINDOWS
	#ifdef CH_BUILD_DLL
		#define CHINATSU_API __declspec(dllexport)
	#else
		#define CHINATSU_API __declspec(dllimport)
	#endif
#else
	#error Chinatsu only supports Windows!
#endif