#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"


NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

template <typename T>
class SUNSHINE_API AllocationUnit
{

public:
	operator T*()
	{
		return (T*)this;
	}

private:
	T _data;
	int32_t _tableIndex;
};


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END