// MessageBus.h
#pragma once

#include <iostream>
#include <malloc.h>
#include "Messages.h"
#include "DataBuffer.h"
#include "../Systems/TestSystem.h"
#include "../Systems/InputSystem.h"

#define MESSAGE_BUFFER_SIZE_SMALL 8
#define ADDRESS_SIZE_64_BIT 8
#define ADDRESS_SIZE_32_BIT 4

namespace ge2d
{
class DataBuffer;
class TestSystem;
class InputSystem;

class MessageBus
{
public:

	MessageBus() {}
	~MessageBus() {}

	bool StartUpStandard();	// initialize MessageBus with memory for 8 messages
	bool StartUp(unsigned int maxMessageBufferSizeInMessages);	// initialize MessageBus w/ maximum number of messages that it can contain
	bool Shutdown();
	void FreeMessageBuffer();
	void ClearMessageBuffer();
	bool PostMessage(EngineMessage message);
	
	// Utility/temporary functions
	bool CheckMessageBufferAndSend();
	bool CheckMessageBufferAndPrintInOrder();
	bool CheckMessageBufferAndPrintByType();
	

public:

	unsigned messageBufferSize;	// number of messages that can be contained in MessageBus
	unsigned messageCounter;	// Current number of messages in MessageBus memory
	EngineMessage *messageBusBasePtr;
	
public:

	DataBuffer *dataBufferPtr;
	TestSystem *testSystem;
	InputSystem *inputSystem;
};

}	// namespace ge2d