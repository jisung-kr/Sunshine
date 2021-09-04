#pragma once
#include "src/IndependenceLayer/IndependenceLayer.h"


NS_SUNSHINE_BEGIN
NS_MEMORYSYSTEM_BEGIN

template <typename T>
class LinearAllocator final
{
public:
	using value_type = T;

	template <class U>
	struct rebind { typedef LinearAllocator<U> other; };

	LinearAllocator() = default;
	~LinearAllocator() = default;

	template <typename U>
	LinearAllocator(const LinearAllocator<U>& other) { }

	T* allocate(size_t ObjectNum, const void* hint) {
		allocate(ObjectNum);
	}

	T* allocate(size_t ObjectNum) {
		return static_cast<T*>(operator new(sizeof(T) * ObjectNum));
	}

	void deallocate(T* p, size_t ObjectNum) {
		operator delete(p);
	}

	size_t max_size() const {
		return std::numeric_limits<size_t>::max() / sizeof(value_type);
	}

	template<typename U, typename... Args>
	void construct(U* p, Args&& ...args) {
		new(p) U(std::forward<Args>(args)...);
	}

	template <typename U>
	void destroy(U* p) {
		p->~U();
	}

protected:
	char* _buffer;
	size_t _bufferSize;
	size_t _offset;

private:

};

NS_MEMORYSYSTEM_END
NS_SUNSHINE_END