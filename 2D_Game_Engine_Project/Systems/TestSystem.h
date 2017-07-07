// TestSystem.h
#pragma once

#include <iostream>
#include "../MessageBus/MessageBus.h"
#include "../MessageBus/Messages.h"

// TestSystem intended to be used to test response to user input of game engine messages
// User/Developer will enter messages, MessageBus will send messages to TestSystem, TestSystem will respond accordingly (print message to Windows console)

namespace ge2d
{
class MessageBus;

class TestSystem 
{
public:

	TestSystem() {}
	~TestSystem() {}

	bool StartUp(MessageBus* initMessageBusPtr);
	bool ShutDown();

	bool HandleMessage(EngineMessage *message);	// Use EngineMessage pointer instead of creating a copy of message

private:

	MessageBus *messageBus;

};

}	// namespace ge2d