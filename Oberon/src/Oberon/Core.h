#pragma once

#ifdef OB_PLATFORM_WINDOWS

	#ifdef OB_BUILD_DLL
		#define OBERON_API __declspec(dllexport)
	#else
		#define OBERON_API __declspec(dllimport)
	#endif

#else
	#error Oberon only supports Windows!
#endif