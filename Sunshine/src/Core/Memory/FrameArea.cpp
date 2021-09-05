#include "FrameArea.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

char* FrameArea::_memory = nullptr;
size_t FrameArea::_memorySize = 0;

void FrameArea::Initialize(char* memory, size_t memorySize)
{
	_memory = memory;
	_memorySize = memorySize;
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END
