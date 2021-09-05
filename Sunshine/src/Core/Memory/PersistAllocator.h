#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"
#include "Memory.h"

NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

extern char* g_persistArea;
extern size_t g_persistMemorySize;
size_t _offset;
template <typename T>
class SUNSHINE_API PersistAllocator final
{
public:
	using value_type = T;

	template <class U>
	struct rebind { typedef PersistAllocator<U> other; };

	PersistAllocator() = default;
	~PersistAllocator() = default;

	template <typename U>
	PersistAllocator(const PersistAllocator<U>&other) { }

	T* allocate(size_t objectNum, const void* hint) {
		allocate(objectNum);
	}

	T* allocate(size_t objectNum) {
		T* allocatedMemory = 
		printf("allocate!!\n");
		return static_cast<T*>(operator new(sizeof(T) * ObjectNum));
	}

	void deallocate(T* ptr, size_t objectNum) {
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
private:

};
NS_MEMORYSYSTEM_END
NS_SUNSHINE_END