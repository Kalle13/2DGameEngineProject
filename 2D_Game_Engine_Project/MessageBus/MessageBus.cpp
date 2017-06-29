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
	// Do not need to call "free(messageBusBasePtr)" in destructor; memory will be freed automatically
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
		
		unsigned currentNumberOfMessages = messageCounter;
		
		if (testSystem != NULL) {
			for (unsigned i = 0; i < currentNumberOfMessages; ++i) {
				
				if (!testSystem->HandleMessage(messageBusBasePtr + i * ADDRESS_SIZE_64_BIT)) {
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

		unsigned currentNumberOfMessages = messageCounter;

		for (unsigned i = 0; i < currentNumberOfMessages; ++i) {
			
			std::cout << "0x" << std::hex << *(messageBusBasePtr + i * ADDRESS_SIZE_64_BIT) << std::endl;
		}
		std::cout << "(MessageBus::CheckMessageBufferAndSend)\tNote: All messages printed" << std::endl;
		return true;
	}
	std::cout << "(MessageBus::CheckMessageBufferAndSend)\tNote: No messages in buffer" << std::endl;
	return false;
}

// Function to print all buffered messages to console in chronological order, but grouped by System type
// TODO: print messageCounter value with each message (acts as a time stamp)
bool MessageBus::CheckMessageBufferAndPrintByType()
{
	// Create function when messages for specific Systems have been defined
	return false;
}

// PostMessage function is used by all Systems to post messages to the message bus
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