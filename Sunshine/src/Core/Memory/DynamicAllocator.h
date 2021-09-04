#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

struct TableRecord
{
	void* Address;
	size_t Size;
};

template <typename T>
class SUNSHINE_API DynamicAllocator
{
public:

	static T* Allocate(size_t size);


};

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END