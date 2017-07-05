// DataBuffer.h
#pragma once

#include <iostream>

// Data Buffer is used to store information that is needed when a message is sent by a System


class DataBuffer
{
public:

	DataBuffer();
	~DataBuffer();

	void DataBufferAllocateMemory(unsigned initMemoryBlockSize);
	void ClearDataBufferMemory();
	void FreeDataBufferMemory();

private:

	unsigned *dataBufferBasePointer;
	unsigned dataBufferSize;
	unsigned dataBufferAddressCounter;

};