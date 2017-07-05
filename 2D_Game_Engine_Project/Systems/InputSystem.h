// InputSystem.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../MessageBus/MessageBus.h"
#include "../MessageBus/Messages.h"

struct MouseInputData
{
	unsigned buttonFlags;
	sf::Vector2f mousePosition;
};

struct KeyboardInputData
{
	unsigned keyboardFlags;
};

struct JoystickInputData
{
	unsigned buttonFlags;
	sf::Vector2f leftStickPosition;
	sf::Vector2f rightStickPosition;
	sf::Vector2f triggerPositions;
};


class InputSystem
{
public:

	InputSystem();
	~InputSystem();

	
	bool HandleMessage(GE2D_MESSAGE *message);

public:
	
	bool mouseEnabled;
	bool keyboardEnabled;
	bool joystickEnabled;

private:

	MessageBus *messageBus;


};