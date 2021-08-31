#pragma once

#include "src/IndependenceLayer/IndependenceLayer.h"
#include "LinearAllocator.h"


/*
 @ Memory Map (2021-08-31)

 -----------
 | Persist |
 -----------
 | Dynamic |
 -----------
 |  Frame  |
 -----------

 Persist is existed program ended
 Dynamic is memory like heap. so, need trace memory system at runtime.
 frame is memory that one frame in game.

*/

NS_SUNSHINE_BEGIN

NS_MEMORYSYSTEM_BEGIN

static char* g_memoryBlock = nullptr;

void Initialize(size_t blockSize, size_t persistSize);


NS_MEMORYSYSTEM_END
NS_SUNSHINE_END