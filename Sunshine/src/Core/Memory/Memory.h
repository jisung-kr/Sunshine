#pragma once

#include "src/IndependenceLayer/IndependenceLayer.h"
#include "LinearAllocator.h"

/*
 @ Memory Map (2021-08-31)

 -----------
 | System  |
 -----------
 | Persist |
 -----------
 | Dynamic |
 -----------
 | Frame   |
 -----------

 System is memory table storage for dynamic area.
 Persist is existed program ended.
 Dynamic is memory like heap. so, need trace memory system at runtime.
 frame is memory that one frame in game.

*/

NS_SUNSHINE_BEGIN

NS_MEMORYSYSTEM_BEGIN


void Initialize(
	size_t blockSize, 
	size_t systemAreaSize, 
	size_t persistAreaSize, 
	size_t dynamicAreaSize,
	size_t frameAreaSize);




NS_MEMORYSYSTEM_END
NS_SUNSHINE_END