// main.cpp
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../2D_Game_Engine_Project/GameEngine/GameEngine2D.h"
/*
#include "../2D_Game_Engine_Project/MessageBus/MessageBus.h"
#include "../2D_Game_Engine_Project/Systems/TestSystem.h"
#include "../2D_Game_Engine_Project/Systems/GameConsoleSystem.h"
#include "../2D_Game_Engine_Project/GameEngine/GameEngine2D.h"
*/
using namespace ge2d;

int main()
{

	// Test DataBuffer, InputSystem, and GameEngine2D classes
	
	MessageBus messageBus;
	DataBuffer dataBuffer;
	TestSystem testSystem;
	
	dataBuffer.StartUp();

	messageBus.dataBufferPtr = &dataBuffer;

	testSystem.messageBusPtr = &messageBus;
	testSystem.dataBufferPtr = &dataBuffer;

	unsigned data = 100;
	unsigned *messageDataPtr = dataBuffer.StoreMessageData(&data, sizeof(data));

	EngineMessage newMessage(TestSend, messageDataPtr);
	std::cout << "newMessage: " << newMessage << std::endl;

	return 0;
}
