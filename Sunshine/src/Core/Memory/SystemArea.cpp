#include "SystemArea.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

char* SystemArea::_memory = nullptr;
size_t SystemArea::_memorySize = 0;

void SystemArea::Initialize(char* memory, size_t memorySize)
{
	_memory = memory;
	_memorySize = memorySize;
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END