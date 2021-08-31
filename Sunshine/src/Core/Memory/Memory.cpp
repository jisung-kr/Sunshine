#include "Memory.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

void Initialize(size_t blockSize, size_t persistSize)
{
	g_memoryBlock = new(std::nothrow) char[blockSize];
	
	_ASSERT(g_memoryBlock != nullptr);

	LinearAllocator::Initialize(g_memoryBlock, persistSize);
	
	
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END