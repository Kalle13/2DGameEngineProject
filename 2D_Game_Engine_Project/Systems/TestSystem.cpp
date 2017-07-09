// TestSystem.cpp
#include "TestSystem.h"
using namespace ge2d;

bool TestSystem::StartUp()
{
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
