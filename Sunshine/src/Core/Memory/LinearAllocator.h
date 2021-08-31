#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"


NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

class LinearAllocator
{
public:
	static void Initialize(char* buffer, size_t size);
	static void* Allocate(size_t size);

protected:
	static char* _buffer;
	static size_t _bufferSize;
	static size_t _offset;
};

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END