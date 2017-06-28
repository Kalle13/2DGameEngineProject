// TestSystem.cpp

#include "TestSystem.h"

TestSystem::TestSystem()
{
	// Empty, for now...
}

TestSystem::TestSystem(MessageBus* initMessageBusPtr)
{
	messageBus = initMessageBusPtr;
}

TestSystem::~TestSystem()
{
	// Empty, for now...	
}

bool TestSystem::HandleMessage(GE2D_MESSAGE message)
{
	bool messageHandled = false; // A message is "handled" if the entire 'case' for that message executes successfully

	switch (message)
	{
	case GE2D_MESSAGE_TEST_SEND:
		std::cout << "MESSAGE_TEST_SEND received" << std::endl;
		messageHandled = messageBus->PostMessage(GE2D_MESSAGE_TEST_REPLY);
		break;
	case GE2D_MESSAGE_TEST_REPLY:
		std::cout << "MESSAGE_TEST_REPLY received" << std::endl;
		messageHandled = true;
		break;
	default:
		break;
	}

	return messageHandled;
}