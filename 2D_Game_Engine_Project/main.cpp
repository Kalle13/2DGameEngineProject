// main.cpp
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MessageBus\MessageBus.h"
#include "MessageBus\Messages.h"
#include "Systems\TestSystem.h"
using namespace ge2d;

int main()
{
	MessageBus messageBus;
	TestSystem testSystem(&messageBus);

	messageBus.testSystem = &testSystem;
		
	if (!messageBus.PostMessage(GE2D_MESSAGE_TEST_SEND)) {
		std::cout << "Failed initial message posting" << std::endl;
	}

	bool checkMessageBuffer = true;

	checkMessageBuffer = messageBus.CheckMessageBufferAndSend();

	messageBus.CheckMessageBufferAndPrintInOrder();

	messageBus.ClearMessageBuffer();	

	
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
	
	return 0;
}
