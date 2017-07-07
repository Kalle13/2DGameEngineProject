// TestSystem.cpp

#include "TestSystem.h"
namespace ge2d
{

bool TestSystem::ShutDown()
{
	// Do nothing at this time
	return true;
}

bool TestSystem::StartUp(MessageBus* initMessageBusPtr)
{
	messageBus = initMessageBusPtr;
	if (messageBus == NULL) return false;

	return true;
}

bool TestSystem::HandleMessage(EngineMessage *message)
{
	bool messageHandled = false; // A message is "handled" if the entire 'case' for that message executes successfully

	ge2d::SystemMessages receivedMessage = message->message;

	switch (receivedMessage)
	{
	case ge2d::TestSend:
		std::cout << "(TestSystem::HandleMessage) message: " << message->message << std::endl;				
		messageHandled = true;
		break;
	default:
		std::cout << "(TestSystem::HandleMessage) No handler for message: " << message->message << std::endl;
		break;
	}

	return messageHandled;
}

}	// namespace ge2d