// MessageBus.cpp

#include "MessageBus.h"
using namespace ge2d;

bool ge2d::MessageBus::StartUpStandard()
{
	messageBusBasePtr = (EngineMessage*)malloc(MESSAGE_BUFFER_SIZE_SMALL * sizeof(EngineMessage));
	messageBufferSize = MESSAGE_BUFFER_SIZE_SMALL;
	messageCounter = 0;

	if (messageBusBasePtr == NULL) return false;

	return true;

}

bool MessageBus::StartUp(unsigned int maxMessageBufferSizeInMessages)
{
	messageBusBasePtr = (EngineMessage*)malloc(maxMessageBufferSizeInMessages * sizeof(EngineMessage));
	messageBufferSize = maxMessageBufferSizeInMessages;
	messageCounter = 0;

	if (messageBusBasePtr == NULL) return false;

	return true;

}

bool MessageBus::Shutdown()
{
	// Nothing for now (memory will be freed in destructor ~MessageBus())
	return true;
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

// TODO: Send messages to systems based on message type (where each message type is defined by available systems)
bool MessageBus::CheckMessageBufferAndSend()
{
	if (messageCounter > 0) {
		
		unsigned currentMessageCount = messageCounter;
		unsigned engineMessageSizeInBytes = sizeof(EngineMessage);

		if (testSystem != NULL) {
			for (unsigned i = 0; i < currentMessageCount; i++) {
				
				if (!testSystem->HandleMessage(((EngineMessage*)(messageBusBasePtr + i * engineMessageSizeInBytes)))) {
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

// Function to print all buffered messages to console in chronological order
// TODO: Specify System type associated with each message
bool MessageBus::CheckMessageBufferAndPrintInOrder()
{
	if (messageCounter > 0) {

		unsigned currentMessageCount = messageCounter;
		unsigned engineMessageSizeInBytes = sizeof(EngineMessage);

		for (unsigned i = 0; i < currentMessageCount; i++) {
			
			std::cout << "0x" << std::hex << *(messageBusBasePtr + i * engineMessageSizeInBytes) << std::endl;
		}
		std::cout << "(MessageBus::CheckMessageBufferAndSend)\tNote: All messages printed" << std::endl;
		return true;
	}
	std::cout << "(MessageBus::CheckMessageBufferAndSend)\tNote: No messages in buffer" << std::endl;
	return false;
}

// Function to print all buffered messages to console in chronological order, but grouped by System type
// TODO: print messageCounter value with each message (address counter acts as a time stamp)
bool MessageBus::CheckMessageBufferAndPrintByType()
{
	// Create function when messages for specific Systems have been defined
	return false;
}

// PostMessage function is used by all Systems to post messages to the message bus
bool MessageBus::PostMessage(EngineMessage message)
{
	unsigned engineMessageSizeInBytes = sizeof(EngineMessage);

	if (messageCounter < messageBufferSize) {
		*((EngineMessage*)(messageBusBasePtr + messageCounter * engineMessageSizeInBytes)) = message;
		messageCounter++;
		return true;
	}
	else {
		std::cout << "(MessageBus::PostMessage)\tERROR: Failed to post message (message buffer full)." << std::endl;
		return false;
	}
}