#include "DynamicArea.h"

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

	return Handle();
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END