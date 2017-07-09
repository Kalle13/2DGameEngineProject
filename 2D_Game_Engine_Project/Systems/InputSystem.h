// InputSystem.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "../MessageBus/MessageBus.h"
#include "../MessageBus/DataBuffer.h"
#include "RenderSystem.h"

namespace ge2d
{
class MessageBus;
class DataBuffer;
class RenderSystem;

enum MouseFlags
{
	leftButton = 0x1,
	rightButton = 0x2,
	middleButton = 0x4
};

typedef struct MouseInputData
{
	unsigned buttonFlags;
	float mouseWheelDelta;
	sf::Vector2i mousePosition;
} structMouseInputData;

// Will need different structs for keyboard/text events
typedef struct KeyboardInputData
{
	unsigned keyboardFlags;
} structKeyboardInputData;

typedef struct JoystickInputData
{
	unsigned buttonFlags;
	sf::Vector2f leftStickPosition;
	sf::Vector2f rightStickPosition;
	sf::Vector2f triggerPositions;
} structJoystickInputData;

// Note: Using std::map to map SFML events to input messages; if map starts to slow down engine, use another (custom?) container
class InputSystem
{
public:

	InputSystem() {}
	~InputSystem() {}

	bool StartUp();
	bool Shutdown();
	
	bool ReadInput();
	bool HandleMessage(EngineMessage *message);

public:
	
	bool mouseEnabled;
	bool keyboardEnabled;
	bool joystickEnabled;
	
	// Create the following structs with the prefix "prev" for comparison between current and previous values (allows for edge detection)
	MouseInputData mouseInputData;
	KeyboardInputData keyboardInputData;
	JoystickInputData joystickInputData;

	std::map<sf::Event::EventType, SystemMessages> inputToMessageMap;

public:

	MessageBus *messageBusPtr;
	DataBuffer *dataBufferPtr;
	RenderSystem *renderSystemPtr;

};

}	// namespace ge2d