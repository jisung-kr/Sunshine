#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

class SUNSHINE_API SystemArea final
{
public:
	struct TableRecord
	{
		char* Address;
		size_t Size;
	};


	SystemArea() = default;
	~SystemArea() = default;

	static void Initialize(char* memory, size_t memorySize);

	static char* GetAddress() { return _memory; }
	static size_t GetSize() { return _memorySize; }


	static size_t FindIndexFromTable(void* ptr);
	static void* FindPointerFromTable(size_t index);

	static size_t GetEmptyIndex();
	static size_t GetEmptyIndex(size_t memorySize);

	static TableRecord* GetTableRecord(size_t index);

private:
	static char* _memory;
	static size_t _memorySize;
};


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END
