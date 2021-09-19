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


size_t SystemArea::FindIndexFromTable(void* ptr)
{
	_ASSERT(_memory != nullptr);

	if (ptr == nullptr)
		return -1;

	size_t recordSize = sizeof(TableRecord);
	size_t recordMaxCount = _memorySize / recordSize;
	size_t findIndex = -1;

	for (size_t cnt = 0; cnt < recordMaxCount; ++cnt)
	{
		TableRecord* curRecord = (TableRecord*)(_memory + cnt * recordSize);
		if (curRecord->Address == ptr)
		{
			findIndex = cnt;
			break;
		}
	}

	return findIndex;
}

///*
void* SystemArea::FindPointerFromTable(size_t index)
{
	_ASSERT(_memory != nullptr);

	size_t recordSize = sizeof(TableRecord);
	size_t recordMaxCount = _memorySize / recordSize;

	if (index < 0 && index > recordMaxCount - 1ll)
		return nullptr;

	TableRecord* curRecord = (TableRecord*)(_memory + index * recordSize);

	return curRecord->Address;
}

size_t SystemArea::GetEmptyIndex()
{
	_ASSERT(_memory != nullptr);

	size_t recordSize = sizeof(TableRecord);
	size_t recordCount = _memorySize / recordSize;
	size_t emptyIndex = -1;

	for (size_t cnt = 0; cnt < recordCount; ++cnt)
	{
		TableRecord* curRecord = (TableRecord*)(_memory + cnt * recordSize);
		if (curRecord->Address == 0)
		{
			emptyIndex = cnt;
			break;
		}
	}

	return emptyIndex;
}

size_t SystemArea::GetEmptyIndex(size_t memorySize)
{
	_ASSERT(_memory != nullptr);

	size_t recordSize = sizeof(TableRecord);
	size_t recordCount = _memorySize / recordSize;
	size_t emptyIndex = -1;

	for (size_t cnt = 0; cnt < recordCount; ++cnt)
	{
		TableRecord* curRecord = (TableRecord*)(_memory + cnt * recordSize);
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
		TableRecord* prevRecord = (TableRecord*)(_memory + (emptyIndex - 1) * recordSize);

		TableRecord* nextRecord = (TableRecord*)(_memory + (emptyIndex + 1) * recordSize);

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

SystemArea::TableRecord* SystemArea::GetTableRecord(size_t index)
{
	size_t recordSize = sizeof(TableRecord);

	return (TableRecord*)(_memory + index * recordSize);
}
//*/


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END