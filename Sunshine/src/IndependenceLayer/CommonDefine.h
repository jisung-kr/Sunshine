#pragma once

#ifdef __STATIC__
	#define SUNSHINE_API 
#elif defined(__DYNAMIC__)
	#define SUNSHINE_API __declspec(dlliexport)
#else
	#define SUNSHINE_API
#endif


#define NS_SUNSHINE_BEGIN namespace Sunshine {
#define NS_SUNSHINE_END }

#define NS_MEMORYSYSTEM_BEGIN namespace MemorySystem{
#define NS_MEMORYSYSTEM_END }