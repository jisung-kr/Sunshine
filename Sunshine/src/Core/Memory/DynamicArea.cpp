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
	// 테이블에서 남는 공간 찾기'ㅠㅐ하ㅗㅇ처ㅡㅎㅇ츄
	// 크기만큼 할당
	// 메모리 테이블에 등록(시스템 영역에 등록)
	// 핸들 리턴

	return Handle();
}

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END