#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"
#include "MemoryTable.h"
#include "MemoryHandle.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

class SUNSHINE_API DynamicArea final
{
public:
	DynamicArea() = default;
	~DynamicArea() = default;

	static void Initialize(char* memory, size_t memorySize);
	static Handle Allocate(size_t size);

private:
	static char* _memory;
	static size_t _memorySize;

};


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END