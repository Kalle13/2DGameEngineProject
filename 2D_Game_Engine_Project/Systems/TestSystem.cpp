// TestSystem.cpp
#include "TestSystem.h"
using namespace ge2d;

bool TestSystem::StartUp(MessageBus *initMessageBusPtr, DataBuffer *initDataBufferPtr)
{

	if (initMessageBusPtr == NULL){
		std::cout << "(TestSystem::StartUp) Error: function received NULL MessageBusPtr." << std::endl;
		return false;
	}
	if (initDataBufferPtr == NULL){
		std::cout << "(TestSystem::StartUp) Error: function received NULL DataBufferPtr." << std::endl;
		return false;
	}

	messageBusPtr = initMessageBusPtr;
	dataBufferPtr = initDataBufferPtr;

	if (messageBusPtr == NULL) {
		std::cout << "(TestSystem::StartUp) Error: messageBusPtr is NULL after assignment." << std::endl;
		return false;
	}
	if (dataBufferPtr == NULL) {
		std::cout << "(TestSystem::StartUp) Error: dataBufferPtr is NULL after assignment." << std::endl;
		return false;
	}

	return true;
}

bool TestSystem::Shutdown()
{
	// Do nothing at this time
	return true;
}

bool TestSystem::HandleMessage(EngineMessage *message)
{
	bool messageHandled = false; // A message is "handled" if the entire 'case' for that message executes successfully

	EngineMessage receivedMessage = *message;

	switch (receivedMessage.message)
	{
	case ge2d::TestSend:
		std::cout << "(TestSystem::HandleMessage) message: " << message->message << "\tdataPtr: "<< message->dataPtr << std::endl;		
		messageHandled = true;
		break;
	default:
		std::cout << "(TestSystem::HandleMessage) No handler for message: " << message->message << std::endl;
		break;
	}

	return messageHandled;
}
