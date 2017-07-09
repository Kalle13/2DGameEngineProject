// DataBuffer.h
#pragma once
#include <iostream>
#include <malloc.h>
#include <string.h>
#include "MessageBus.h"
#include "../Systems/InputSystem.h"

#define DATA_BUFFER_SIZE 200

namespace ge2d
{

// Data Buffer is used to store information that is needed when a message is sent by a System
// EngineMessage dataPtr's will point to data in memory allocated by DataBuffer
class DataBuffer
{
public:

	DataBuffer() {}
	~DataBuffer() {}

	bool StartUp();
	bool Shutdown();

	bool DataBufferAllocateMemory(unsigned initBufferSizeInBytes);
	bool ClearDataBufferMemory();
	bool FreeDataBufferMemory();

	unsigned* StoreMessageData(const unsigned *dataStackPtr, const unsigned& dataSizeInBytes);

public:

	unsigned *dataBufferBasePointer;
	unsigned dataBufferSizeInBytes;
	unsigned dataBufferAddressCounter;

};

}	// namespace ge2d