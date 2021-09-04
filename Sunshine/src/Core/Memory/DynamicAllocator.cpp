#include "DynamicAllocator.h"
#include "MemoryHandle.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN


extern char* g_systemArea;
extern size_t g_systemMemorySize;

extern char* g_dynamicArea;
extern size_t g_dynamicMemorySize;


template <typename T>
T* DynamicAllocator<T>::Allocate(size_t size)
{
	_ASSERT(g_systemArea != nullptr);

	int recordSize = sizeof(TableRecord);
	int recordCount = g_systemMemorySize / recordSize;
	int emptyIndex = -1;

	for (int cnt = 0; cnt < recordCount; ++cnt)
	{
		TableRecord* curRecord = (TableRecord*)(g_systemArea + cnt * recordSize);
		if (curRecord->Address == 0)
		{
			emptyIndex = cnt;
			break;
		}
	}

	if (emptyIndex == -1)
		return nullptr;

	void* memoryAddr = nullptr;
	TableRecord* curRecord = (TableRecord*)(g_systemArea + emptyIndex * recordSize);
	if (emptyIndex == 0)
		memoryAddr = g_dynamicArea;
	else
	{
		TableRecord* prevRecord = (TableRecord*)(g_systemArea + (emptyIndex - 1) * recordSize);
		memoryAddr = (char*)prevRecord->Address + prevRecord->Size;
	}
	curRecord->Address = memoryAddr;
	curRecord->Size = sizeof(AllocationUnit<T>);
	return nullptr;
}



NS_MEMORYSYSTEM_END
NS_SUNSHINE_END

