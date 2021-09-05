#include "MemoryTable.h"


NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

extern char* g_systemArea;
extern size_t g_systemMemorySize;

extern char* g_dynamicArea;
extern size_t g_dynamicMemorySize;

size_t FindIndexFromTable(void* ptr)
{
	_ASSERT(g_systemArea != nullptr);

	size_t recordSize = sizeof(TableRecord);
	size_t recordMaxCount = g_systemMemorySize / recordSize;
	size_t findIndex = -1;

	for (size_t cnt = 0; cnt < recordMaxCount; ++cnt)
	{
		TableRecord* curRecord = (TableRecord*)(g_systemArea + cnt * recordSize);
		if (curRecord->Address == ptr)
		{
			findIndex = cnt;
			break;
		}
	}

	return findIndex;
}

void* FindPointerFromTable(size_t index)
{
	_ASSERT(g_systemArea != nullptr);

	size_t recordSize = sizeof(TableRecord);
	size_t recordMaxCount = g_systemMemorySize / recordSize;

	if (index < 0 && index > recordMaxCount - 1ll)
		return nullptr;

	TableRecord* curRecord = (TableRecord*)(g_systemArea + index * recordSize);

	return curRecord->Address;
}

size_t GetEmptyIndex()
{
	_ASSERT(g_systemArea != nullptr);

	int recordSize = sizeof(TableRecord);
	int recordCount = g_systemMemorySize / recordSize;
	size_t emptyIndex = -1;

	for (size_t cnt = 0; cnt < recordCount; ++cnt)
	{
		TableRecord* curRecord = (TableRecord*)(g_systemArea + cnt * recordSize);
		if (curRecord->Address == 0)
		{
			emptyIndex = cnt;
			break;
		}
	}

	return emptyIndex;
}

size_t GetEmptyIndex(size_t memorySize)
{
	_ASSERT(g_systemArea != nullptr);

	size_t recordSize = sizeof(TableRecord);
	size_t recordCount = g_systemMemorySize / recordSize;
	size_t emptyIndex = -1;

	for (size_t cnt = 0; cnt < recordCount; ++cnt)
	{
		TableRecord* curRecord = (TableRecord*)(g_systemArea + cnt * recordSize);
		if (curRecord->Address == 0)
		{
			emptyIndex = cnt;
			break;
		}
	}
	if (emptyIndex == -1)
		return -1;
	else if (emptyIndex == 0)
		return emptyIndex;
	else
	{
		TableRecord* prevRecord = (TableRecord*)(g_systemArea + (emptyIndex - 1) * recordSize);

		TableRecord* nextRecord = (TableRecord*)(g_systemArea + (emptyIndex + 1) * recordSize);

		if (nextRecord->Address == 0)
		{
			return emptyIndex;
		}
		else
		{
			if ((char*)nextRecord->Address - ((char*)prevRecord->Address + prevRecord->Size) <= memorySize)
			{
				return emptyIndex;
			}
			else
			{
				while ((emptyIndex = GetEmptyIndex(memorySize)) != -1)
				{

				}
				return emptyIndex;
			}
		}
	}

	return -1;
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END