// MessageBus.cpp

#include "MessageBus.h"

MessageBus::MessageBus()
{
	messageBusBasePtr = (GE2D_MESSAGE*)malloc(MESSAGE_BUFFER_SIZE_SMALL);
	messageBufferSize = MESSAGE_BUFFER_SIZE_SMALL;
	messageCounter = 0;
}

MessageBus::MessageBus(unsigned int initMemoryBlockSize)
{
	messageBusBasePtr = (GE2D_MESSAGE*)malloc(initMemoryBlockSize);
	messageBufferSize = initMemoryBlockSize;
	messageCounter = 0;
}

MessageBus::~MessageBus()
{	
	//FreeMessageBuffer();
}

void MessageBus::FreeMessageBuffer()
{
	free(messageBusBasePtr);
}

// Function to allow overwrite of message buffer
void MessageBus::ClearMessageBuffer()
{
	messageCounter = 0;
}

// ToDo: Send messages to systems based on message type (where each message type is defined by available systems)
bool MessageBus::CheckMessageBufferAndSend()
{
	if (messageCounter > 0) {
		if (testSystem != NULL) {
			for (unsigned i = 0; i < messageCounter; ++i) {
				if (!testSystem->HandleMessage(*(messageBusBasePtr + i * sizeof(GE2D_MESSAGE)))) {
					return false;
				}
			}
			std::cout << "(MessageBus::CheckMessageBufferAndSend)\tNote: All messages sent" << std::endl;
			return true;
		}
		std::cout << "(MessageBus::CheckMessageBufferAndSend)\t--Warning--: testSystem pointer is NULL" << std::endl;
		return false;
	}

	std::cout << "(MessageBus::CheckMessageBufferAndSend)\tNote: No messages in buffer" << std::endl;
	return false;
}

bool MessageBus::PostMessage(GE2D_MESSAGE message)
{
	if (messageCounter < messageBufferSize) {
		*(messageBusBasePtr + messageCounter * sizeof(GE2D_MESSAGE)) = message;
		messageCounter++;
		return true;
	}
	else {
		std::cout << "(MessageBus::PostMessage)\tERROR: Failed to post message (message buffer full)." << std::endl;
		return false;
	}
}