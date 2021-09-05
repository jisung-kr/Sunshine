#include "Memory.h"
#include "SystemArea.h"
#include "PersistArea.h"
#include "DynamicArea.h"
#include "FrameArea.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

char* g_memoryBlock = nullptr;
size_t g_blockSize = 0;


void Initialize(size_t blockSize,
	size_t systemAreaSize,
	size_t persistAreaSize,
	size_t dynamicAreaSize,
	size_t frameAreaSize)
{
	g_memoryBlock = new(std::nothrow) char[blockSize];
	_ASSERT(g_memoryBlock != nullptr);
	g_blockSize = blockSize;
	
	printf("Memory Block Initialize : %lld bytes\n", blockSize);

	char* systemAddr = g_memoryBlock;
	printf("System Area: 0x%08llp ~ 0x%08llp\n", systemAddr, systemAddr + systemAreaSize - 1);
	memset((void*)systemAddr, 0, systemAreaSize);
	SystemArea::Initialize(systemAddr, systemAreaSize);

	char* persistAddr = systemAddr + systemAreaSize;
	printf("Persist Area: 0x%08llp ~ 0x%08llp\n", persistAddr, persistAddr + persistAreaSize - 1);
	PersistArea::Initialize((char*)persistAddr, persistAreaSize);

	char* dynamicAddr = persistAddr + persistAreaSize;
	printf("Dynamic Area: 0x%08llp ~ 0x%08llp\n", dynamicAddr, dynamicAddr + dynamicAreaSize - 1);
	DynamicArea::Initialize(dynamicAddr, dynamicAreaSize);

	char* frameAddr = dynamicAddr + dynamicAreaSize;
	printf("Frame Area: 0x%08llp ~ 0x%08llp\n", frameAddr, frameAddr + frameAreaSize - 1);
	FrameArea::Initialize(frameAddr, frameAreaSize);
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END