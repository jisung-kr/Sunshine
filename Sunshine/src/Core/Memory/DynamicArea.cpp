#include "DynamicArea.h"
#include "SystemArea.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN
char* DynamicArea::_memory = nullptr;
size_t DynamicArea::_memorySize = 0;

void DynamicArea::Initialize(char* memory, size_t memorySize)
{
	_memory = memory;
	_memorySize = memorySize;
}

Handle DynamicArea::Allocate(size_t size)
{
	// ���̺��� ���� ���� ã��'�Ф��ϤǤ�ó�Ѥ�����
	// ũ�⸸ŭ �Ҵ�
	// �޸� ���̺� ���(�ý��� ������ ���)
	// �ڵ� ����

	size_t index = SystemArea::GetEmptyIndex(size);

	if (index == -1)
		return Handle(nullptr);

	char* memoryAddr = nullptr;
	if (index == 0)
		memoryAddr = _memory;
	else
	{
		SystemArea::TableRecord* prevRecord = SystemArea::GetTableRecord(index - 1);
		memoryAddr = prevRecord->Address + prevRecord->Size;
	}

	SystemArea::TableRecord* curRecord = SystemArea::GetTableRecord(index);
	curRecord->Address = memoryAddr;
	curRecord->Size = size;

	//printf("allocate!!\n");
	return Handle(memoryAddr);
}

void DynamicArea::Deallocate(const Handle& handle)
{
	size_t index = handle.GetIndex();
	if (index == -1)
		return;

	SystemArea::TableRecord* record = SystemArea::GetTableRecord(index);

	record->Address = 0;
	record->Size = 0;

	//printf("deallocate!!\n");
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END