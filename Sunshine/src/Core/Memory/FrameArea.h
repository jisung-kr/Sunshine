#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

class SUNSHINE_API FrameArea final
{
public:
	FrameArea() = default;
	~FrameArea() = default;

	static void Initialize(char* memory, size_t memorySize);

private:
	static char* _memory;
	static size_t _memorySize;
	static size_t _offset;
};

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END