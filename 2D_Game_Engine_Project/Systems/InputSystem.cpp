// InputSystem.cpp

#include "InputSystem.h"
using namespace ge2d;

bool InputSystem::StartUp()
{
	if (messageBusPtr == NULL) {
		std::cout << "(InputSystem::StartUp) Error: messageBusPtr uninitialized" << std::endl;
		return false;
	}
	if (renderSystemPtr == NULL) {
		std::cout << "(InputSystem::StartUp) Error: renderSystemPtr uninitialized" << std::endl;
		return false;
	}

	keyboardEnabled = true;
	mouseEnabled = true;
	joystickEnabled = sf::Joystick::isConnected(0);

	inputToMessageMap[sf::Event::KeyPressed] = InputKeyPressed;
	inputToMessageMap[sf::Event::KeyReleased] = InputKeyReleased;
	inputToMessageMap[sf::Event::MouseMoved] = InputMouseEvent;
	inputToMessageMap[sf::Event::MouseButtonPressed] = InputMouseEvent;
	inputToMessageMap[sf::Event::MouseButtonReleased] = InputMouseEvent;
	inputToMessageMap[sf::Event::MouseWheelScrolled] = InputMouseEvent;
	if (joystickEnabled) {
		inputToMessageMap[sf::Event::JoystickButtonPressed] = InputJoystickEvent;
	}
	
	return true;
}

bool InputSystem::Shutdown()
{
	return true;
}

bool InputSystem::ReadInput()
{
	// Use flags to post messages at end of ReadInput() function
	bool flagKeyPressed = false;
	bool flagKeyReleased = false;
	bool flagMouseWheelScrolled = false;

	if (renderSystemPtr->window.isOpen()) {

		sf::Event event;
		while (renderSystemPtr->window.pollEvent(event)) {

			if (mouseEnabled) 
			{
				mouseInputData.mouseWheelDelta = 0;

				if (event.type == sf::Event::MouseWheelScrolled) 
				{
					if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) 
					{
						flagMouseWheelScrolled = true;
						mouseInputData.mouseWheelDelta = event.mouseWheelScroll.delta;
						mouseInputData.mousePosition = sf::Vector2i(event.mouseWheelScroll.x, event.mouseWheelScroll.y);
					}
				}
			}

			if (keyboardEnabled) {
				if (event.type == sf::Event::KeyPressed) {
					flagKeyPressed = true;
				}
				if (event.type == sf::Event::KeyReleased) {
					flagKeyReleased = true;
				}

			}
		}

		if (mouseEnabled) {
			
			mouseInputData.buttonFlags = 0;
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				mouseInputData.buttonFlags |= MouseFlags::leftButton;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				mouseInputData.buttonFlags |= MouseFlags::rightButton;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
				mouseInputData.buttonFlags |= MouseFlags::middleButton;
			}
			// Only get mouse position if no mouse wheel scroll event was detected
			if (!flagMouseWheelScrolled) {
				mouseInputData.mousePosition = sf::Mouse::getPosition(renderSystemPtr->window);
			}
		}

	}

	if (keyboardEnabled) {
		if (flagKeyPressed) {

		}

		if (flagKeyReleased) {

		}
	}
	// Always send mouse data (if mouse enabled)
	if (mouseEnabled) {

	}

	return true;
}

bool InputSystem::HandleMessage(EngineMessage *message)
{
	bool messageHandled = false;

	EngineMessage receivedMessage = *message;

	switch (receivedMessage.message)
	{
	case InputRead:
		ReadInput();
		messageHandled = true;
		break;
	case InputRemap:
		std::cout << "(InputSystem::HandleMessage) Need to handle case 'InputRemap'" << std::endl;
		break;
	default:
		std::cout << "(InputSystem::HandleMessage) No handler for message: " << message->message << std::endl;
		break;
	}

	return messageHandled;
}