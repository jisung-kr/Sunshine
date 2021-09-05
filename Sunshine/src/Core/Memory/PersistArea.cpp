#include "PersistArea.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

char* PersistArea::_memory = nullptr;
size_t PersistArea::_memorySize = 0;
size_t PersistArea::_offset = 0;

void PersistArea::Initialize(char* memory, size_t memorySize)
{
	_memory = memory;
	_memorySize = memorySize;
	_offset = 0;
}

void* PersistArea::Allocate(size_t size)
{
	_ASSERT(_offset + size <= _memorySize);
	void* allocatedMemory = _memory + _offset;
	_offset += size;

	return allocatedMemory;
}


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END