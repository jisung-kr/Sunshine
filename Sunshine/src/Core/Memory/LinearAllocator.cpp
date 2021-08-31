#include "LinearAllocator.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

char* LinearAllocator::_buffer = nullptr;
size_t LinearAllocator::_bufferSize = 0;
size_t LinearAllocator::_offset = 0;

void LinearAllocator::Initialize(char* buffer, size_t size)
{
	_buffer = buffer;
	_bufferSize = size;
	_offset = 0;
}

void* LinearAllocator::Allocate(size_t size)
{
	char* allocatedMemory = _buffer + _offset;
	_offset += size;
	return allocatedMemory;
}


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END