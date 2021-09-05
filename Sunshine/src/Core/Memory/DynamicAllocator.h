#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"
#include "MemoryTable.h"
#include "MemoryHandle.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

template <typename T>
class SUNSHINE_API DynamicAllocator final
{

public:
	using value_type = T;

	template <class U>
	struct rebind { typedef DynamicAllocator<U> other; };

	DynamicAllocator() = default;
	~DynamicAllocator() = default;

	template <typename U>
	DynamicAllocator(const DynamicAllocator<U>&other) { }

	Handle<T> allocate(size_t objectNum, const void* hint) 
	{
		allocate(objectNum);
	}

	Handle<T> allocate(size_t objectNum) 
	{
		size_t index = GetEmptyIndex(objectNum * sizeof(T));

		if (index == -1)
			return nullptr;

		void* memoryAddr = nullptr;
		TableRecord* curRecord = (TableRecord*)(g_systemArea + index * recordSize);
		if (index == 0)
			memoryAddr = g_dynamicArea;
		else
		{
			TableRecord* prevRecord = (TableRecord*)(g_systemArea + (emptyIndex - 1) * recordSize);
			memoryAddr = (char*)prevRecord->Address + prevRecord->Size;
		}
		curRecord->Address = memoryAddr;
		curRecord->Size = sizeof(T * objectNum));

		printf("allocate!!\n");

		return Handle<T>(memoryAddr);
	}

	void deallocate(Handle<T> p, size_t objectNum) {
		printf("deallocate!\n");
		//operator delete(p);
	}

	size_t max_size() const {
		return std::numeric_limits<size_t>::max() / sizeof(value_type);
	}

	template<typename U, typename... Args>
	void construct(U * p, Args&& ...args) {
		new(p) U(std::forward<Args>(args)...);
	}

	template <typename U>
	void destroy(U * p) {
		p->~U();
	}
};

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END