// TestSystem.cpp

#include "TestSystem.h"
using namespace ge2d;

bool TestSystem::ShutDown()
{
	// Do nothing at this time
}

bool TestSystem::StartUp(MessageBus* initMessageBusPtr)
{
	messageBus = initMessageBusPtr;
}

bool TestSystem::HandleMessage(GE2D_MESSAGE *message)
{
	bool messageHandled = false; // A message is "handled" if the entire 'case' for that message executes successfully

	switch (*message)
	{
	case message->:
		std::cout << "(TestSystem::HandleMessage) message: " << *message << std::endl;
		std::cout << "MESSAGE_TEST_SEND received" << std::endl;
		//messageHandled = messageBus->PostMessage(GE2D_MESSAGE_TEST_REPLY);
		//std::cout << "MESSAGE_TEST_REPLY sent" << std::endl;
		messageHandled = true;
		break;
	default:
		std::cout << "(TestSystem::HandleMessage) No handler for message: " << *message << std::endl;		
		break;
	}

	return messageHandled;
}