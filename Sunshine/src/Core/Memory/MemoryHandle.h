#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"
#include "MemoryTable.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN


class SUNSHINE_API Handle final
{
public:
	Handle(char* actualAddress)
	{
		_tableIndex = FindIndexFromTable(actualAddress);
	}

	~Handle()
	{

	}
	/*
	operator T* ()
	{
		_ASSERT(g_systemArea != nullptr);

		void ptr = FindPointerFromTable(_tableIndex);

		return (T*)ptr;
	}
	operator T()
	{
		_ASSERT(g_systemArea != nullptr);

		void ptr = FindPointerFromTable(_tableIndex);

		_ASSERT(ptr != nullptr);

		return *ptr;
	}
	//*/


private:
	size_t _tableIndex;
};


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END