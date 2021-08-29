#pragma once

#ifdef __STATIC
	#define SUNSHINE_API 
#elif defined(__DYNAMIC)
	#define SUNSHINE_API __declspec(dlliexport)
#endif


#define NS_SUNSHINE_START namespace Sunshine {
#define NS_SUNSHINE_END }