#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"
#include "SystemArea.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN


class SUNSHINE_API Handle final
{
public:
	Handle(char* actualAddress)
	{
		_tableIndex = SystemArea::FindIndexFromTable(actualAddress);
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

	size_t GetIndex() const { return _tableIndex; }


private:
	size_t _tableIndex;
};


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END