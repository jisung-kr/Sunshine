
#include "src/Sunshine.h"
#include <vector>
#include <chrono>

#define BLOCK_SIZE 524288000	// 500MiB
#define SYSTEM_SIZE 10485760	// 10MiB
#define PERSIST_SIZE 167772160	// 160MiB
#define DYNAMIC_SIZE 188743680	// 180MiB
#define FRAME_SIZE 157286400	// 150MiB

using namespace std;

int main()
{
	Sunshine::MemorySystem::Initialize(BLOCK_SIZE, SYSTEM_SIZE, PERSIST_SIZE, DYNAMIC_SIZE, FRAME_SIZE);

	int count = 100000;
	{
		auto start = std::chrono::system_clock::now();
		for (int i = 0; i < count; ++i)
			Sunshine::MemorySystem::PersistAllocator::Allocate(sizeof(int));
		auto end = std::chrono::system_clock::now();

		printf("PersistAllocator : %lldms\n",
			std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	}

	{
		auto start = std::chrono::system_clock::now();

		for (int i = 0; i < count; ++i)
			new int;

		auto end = std::chrono::system_clock::now();

		printf("Default New : %lldms\n",
			std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	}

	
	vector<int, Sunshine::MemorySystem::LinearAllocator<int>> test;
	test.push_back(10);
	test.push_back(10);
	test.push_back(10);
	test.push_back(10);
	

	return 0;
}