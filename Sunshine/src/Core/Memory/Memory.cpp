#include "Memory.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

char* g_memoryBlock = nullptr;
char* g_systemArea = nullptr;
char* g_persistArea = nullptr;
char* g_dynamicArea = nullptr;
char* g_frameArea = nullptr;

size_t g_blocSize = 0; 
size_t g_systemMemorySize = 0;
size_t g_persistMemorySize = 0;
size_t g_dynamicMemorySize = 0;
size_t g_frameMemorySize = 0;

void Initialize(size_t blockSize,
	size_t systemAreaSize,
	size_t persistAreaSize,
	size_t dynamicAreaSize,
	size_t frameAreaSize)
{
	g_memoryBlock = new(std::nothrow) char[blockSize];
	_ASSERT(g_memoryBlock != nullptr);
	g_blocSize = blockSize;
	
	printf("Memory Block Initialize : %lld bytes\n", blockSize);

	size_t systemAddr = (size_t)g_memoryBlock;
	printf("System Area: 0x%08llx ~ 0x%08llx\n", systemAddr, systemAddr + systemAreaSize - 1);
	memset((void*)systemAddr, 0, systemAreaSize);
	g_systemArea = (char*)systemAddr;
	g_systemMemorySize = systemAreaSize;

	size_t persistAddr = systemAddr + systemAreaSize;
	printf("Persist Area: 0x%08llx ~ 0x%08llx\n", persistAddr, persistAddr + persistAreaSize - 1);
	g_persistArea = (char*)persistAddr;
	g_persistMemorySize = persistAreaSize;
	
	PersistAllocator::Initialize(g_persistArea, g_persistMemorySize);

	size_t dynamicAddr = persistAddr + persistAreaSize;
	printf("Dynamic Area: 0x%08llx ~ 0x%08llx\n", dynamicAddr, dynamicAddr + dynamicAreaSize - 1);
	g_dynamicArea = (char*)dynamicAddr;
	g_dynamicMemorySize = dynamicAreaSize;

	size_t frameAddr = dynamicAddr + dynamicAreaSize;
	printf("Frame Area: 0x%08llx ~ 0x%08llx\n", frameAddr, frameAddr + frameAreaSize - 1);
	g_frameArea = (char*)frameAddr;
	g_frameMemorySize = frameAreaSize;
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END