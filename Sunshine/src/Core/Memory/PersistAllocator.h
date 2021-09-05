#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"
#include "Memory.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

extern char* g_persistArea;
extern size_t g_persistMemorySize;
size_t _persistOffset;


class SUNSHINE_API PersistAllocator final
{
public:
	//using value_type = T;

	//template <class U>
	//struct rebind { typedef PersistAllocator<U> other; };

	PersistAllocator() = default;
	~PersistAllocator() = default;

	//template <typename U>
	//PersistAllocator(const PersistAllocator<U>&other) { }

	void* allocate(size_t objectNum, const void* hint) {
		allocate(objectNum);
	}

	static void* allocate(size_t objectNum) {
		void* allocatedMemory = g_persistArea + _persistOffset;
		_persistOffset = objectNum;
		printf("allocate!!\n");
		return static_cast<void*>(allocatedMemory);
	}

	static void deallocate(void* ptr, size_t objectNum) {
		printf("Persist Not deallocated!\n");
	}

	size_t max_size() const {
		return std::numeric_limits<size_t>::max();
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