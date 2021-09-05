#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"


NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

class SUNSHINE_API PersistArea final
{
public:
	PersistArea() = default;
	~PersistArea() = default;

	static void Initialize(char* memoryAddr, size_t memorySize);
	static void* Allocate(size_t size);

private:
	static char* _memory;
	static size_t _memorySize;
	static size_t _offset;
};


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END