// TestSystem.h
#pragma once

#include <iostream>
#include "../MessageBus/MessageBus.h"

// TestSystem intended to be used to test response to user input of game engine messages
// User/Developer will enter messages, MessageBus will send messages to TestSystem, TestSystem will respond accordingly (print message to Windows console)

class MessageBus;

class TestSystem 
{
public:

	TestSystem();
	TestSystem(MessageBus* initMessageBusPtr);
	~TestSystem();

	bool HandleMessage(GE2D_MESSAGE *message);	// Use message pointer instead of creating a copy of message

private:

	MessageBus *messageBus;

};
