// main.cpp
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../2D_Game_Engine_Project/MessageBus/MessageBus.h"
#include "../2D_Game_Engine_Project/MessageBus/Messages.h"
#include "../2D_Game_Engine_Project/Systems/TestSystem.h"
using namespace ge2d;

int main()
{

	MessageBus messageBus;
	TestSystem testSystem;

	messageBus.StartUpStandard();
	testSystem.StartUp(&messageBus);

	messageBus.testSystem = &testSystem;
		
	EngineMessage testMessageSend(SystemMessages::TestSend, NULL);
	EngineMessage testMessageReply(SystemMessages::TestReply, NULL);

	if (!messageBus.PostMessage(testMessageSend)) {
		std::cout << "Failed initial message posting" << std::endl;
	}

	messageBus.PostMessage(testMessageReply);

	bool checkMessageBuffer = true;

	checkMessageBuffer = messageBus.CheckMessageBufferAndSend();

	messageBus.CheckMessageBufferAndPrintInOrder();

	messageBus.ClearMessageBuffer();	

	/*
	sf::VideoMode videoMode(800, 600);
	sf::RenderWindow window(videoMode, "game window");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
		
		window.clear(sf::Color(255,255,0));
		window.display();
	}
	*/
	return 0;
}
