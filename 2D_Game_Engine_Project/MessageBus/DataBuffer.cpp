// DataBuffer.cpp
#include "DataBuffer.h"
using namespace ge2d;

bool DataBuffer::StartUp()
{
	dataBufferBasePointer = (unsigned*)malloc(DATA_BUFFER_SIZE);
	if (dataBufferBasePointer == NULL) {
		std::cout << "(DataBuffer::StartUp) Error: Failed to allocate memory for Data Buffer" << std::endl;
		return false;
	}

	dataBufferSizeInBytes = DATA_BUFFER_SIZE;
	dataBufferAddressCounter = 0;

	return true;
}

bool DataBuffer::Shutdown()
{
	return true;
}

bool DataBuffer::DataBufferAllocateMemory(unsigned initBufferSizeInBytes)
{
	if (dataBufferBasePointer != NULL) {
		free(dataBufferBasePointer);
	}

	dataBufferBasePointer = (unsigned*)malloc(initBufferSizeInBytes);

	if (dataBufferBasePointer == NULL) {
		std::cout << "(DataBuffer::DataBufferAllocateMemory) Error: Failed to allocate memory for Data Buffer" << std::endl;
		return false;
	}

	dataBufferSizeInBytes = initBufferSizeInBytes;
	dataBufferAddressCounter = 0;

	return true;

}

bool DataBuffer::ClearDataBufferMemory()
{
	dataBufferAddressCounter = 0;
	return true;
}

bool DataBuffer::FreeDataBufferMemory()
{
	if (dataBufferBasePointer == NULL) {
		std::cout << "(DataBuffer::FreeDataBufferMemory) Error: null Data Buffer Base Pointer" << std::endl;
		return false;
	}

	free(dataBufferBasePointer);
	return true;
}

unsigned* DataBuffer::StoreMessageData(const unsigned *dataStackPtr, const unsigned& dataSizeInBytes)
{
	unsigned* returnPtr;

	//Check that data will not extend beyond size of buffer
	if (dataBufferAddressCounter + dataSizeInBytes < dataBufferSizeInBytes) {

		returnPtr = (unsigned*)memcpy((void*)(dataBufferBasePointer + dataBufferAddressCounter), (void*)dataStackPtr, dataSizeInBytes);

		if (returnPtr == NULL) {
			std::cout << "(DataBuffer::StoreMessageData) Error: Failed to store data" << std::endl;
		}

		return returnPtr;
	} 
	else {
		std::cout << "(DataBuffer::StoreMessageData) Error: Failed to store data. New data would cause buffer overflow." << std::endl;
		return NULL;
	}
}