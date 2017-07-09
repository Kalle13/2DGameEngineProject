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

struct one {
	unsigned a;
};

struct two {
	one first;
	unsigned b;
};

struct three {
	two second;
	unsigned c;
};

struct four {
	three third;
	unsigned d;
};

int main()
{
	/*
	std::cout << "sizeof(one) = " << sizeof(one) << std::endl;
	std::cout << "sizeof(two) = " << sizeof(two) << std::endl;
	std::cout << "sizeof(three) = " << sizeof(three) << std::endl;
	std::cout << "sizeof(four) = " << sizeof(four) << std::endl;

	unsigned a = 4;
	unsigned* ptr = &a;
	unsigned* ptr2;
	std::cout << "unsigned a = " << a << "\n*((void*)(ptr)) = " << ((void*)(ptr)) << std::endl;
	std::cout << "sizeof(ptr) = " << sizeof(ptr) << std::endl;
	ptr2 = (unsigned*)(ptr + a);
	std::cout << "ptr + 4 = " << ptr2 << std::endl;
	*/

	// Test DataBuffer, InputSystem, and GameEngine2D classes

	MessageBus messageBus;
	DataBuffer dataBuffer;
	TestSystem testSystem;
	
	dataBuffer.StartUp();

	messageBus.dataBufferPtr = &dataBuffer;

	testSystem.messageBusPtr = &messageBus;
	testSystem.dataBufferPtr = &dataBuffer;

	unsigned data1 = 100;
	unsigned data2 = 200;
	unsigned data3 = 300;
	unsigned *messageDataPtr1 = dataBuffer.StoreMessageData(&data1, sizeof(data1));
	unsigned *messageDataPtr2 = dataBuffer.StoreMessageData(&data2, sizeof(data2));
	unsigned *messageDataPtr3 = dataBuffer.StoreMessageData(&data3, sizeof(data3));

	EngineMessage newMessage1(TestSend, messageDataPtr1);
	EngineMessage newMessage2(InputRead, messageDataPtr2);
	EngineMessage newMessage3(InputDisable, messageDataPtr3);
	std::cout << "newMessage1: " << newMessage1 << "\tData: " << *(newMessage1.dataPtr) << std::endl;
	std::cout << "newMessage2: " << newMessage2 << "\tData: " << *(newMessage2.dataPtr) << std::endl;
	std::cout << "newMessage3: " << newMessage3 << "\tData: " << *(newMessage3.dataPtr) << std::endl;
	
	return 0;
}
