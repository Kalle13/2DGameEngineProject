// MessageBus.h
#pragma once

#include <iostream>
#include <malloc.h>
#include "Messages.h"
#include "../Systems/TestSystem.h"

#define MESSAGE_BUFFER_SIZE_SMALL 4
#define ADDRESS_SIZE_64_BIT 8
#define ADDRESS_SIZE_32_BIT 4

class TestSystem;

	class MessageBus
	{
	public:

		MessageBus();
		MessageBus(unsigned int initMemoryBlockSize);
		~MessageBus();

		void FreeMessageBuffer();
		void ClearMessageBuffer();
		bool CheckMessageBufferAndSend();
		bool CheckMessageBufferAndPrintInOrder();
		bool CheckMessageBufferAndPrintByType();
		bool PostMessage(GE2D_MESSAGE message);

	public:

		unsigned messageBufferSize;
		unsigned messageCounter;
		unsigned *messageBusBasePtr;

	public:

		TestSystem *testSystem;

	};