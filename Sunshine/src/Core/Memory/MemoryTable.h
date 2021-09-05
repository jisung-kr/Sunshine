#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

struct TableRecord
{
	void* Address;
	size_t Size;
};


size_t FindIndexFromTable(void* ptr);
void* FindPointerFromTable(size_t index);

size_t GetEmptyIndex();
size_t GetEmptyIndex(size_t memorySize);

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END