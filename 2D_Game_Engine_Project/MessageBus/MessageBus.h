// MessageBus.h
#pragma once

#include <iostream>
#include <malloc.h>
#include "Messages.h"
#include "../Systems/TestSystem.h"

#define MESSAGE_BUFFER_SIZE_SMALL 4
#define ADDRESS_SIZE_64_BIT 8
#define ADDRESS_SIZE_32_BIT 4

namespace ge2d
{
class TestSystem;

class MessageBus
{
public:

	MessageBus() {}
	~MessageBus() {}

	bool StartUpStandard();
	bool StartUp(unsigned int initMemoryBlockSize);
	void FreeMessageBuffer();
	void ClearMessageBuffer();
	bool PostMessage(Message message);

	// Utility/temporary functions
	bool CheckMessageBufferAndSend();
	bool CheckMessageBufferAndPrintInOrder();
	bool CheckMessageBufferAndPrintByType();

public:

	unsigned messageBufferSize;
	unsigned messageAddressCounter;
	unsigned *messageBusBasePtr;

public:

	TestSystem *testSystem;

};

}	// namespace ge2d