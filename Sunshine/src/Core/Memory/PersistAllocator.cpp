#include "PersistAllocator.h"


NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

char* PersistAllocator::_buffer = nullptr;
size_t PersistAllocator::_bufferSize = 0;
size_t PersistAllocator::_offset = 0;

void PersistAllocator::Initialize(char* buffer, size_t size)
{
    _buffer = buffer;
    _bufferSize = size;
    _offset = 0;
}

void* PersistAllocator::Allocate(size_t size)
{
    _ASSERT(_offset < _bufferSize);
    void* allocatedMemory = _buffer + _offset;
    _offset += size;
    return allocatedMemory;
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END