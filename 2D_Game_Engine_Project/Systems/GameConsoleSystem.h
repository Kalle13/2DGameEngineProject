// GameConsole.h
#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../MessageBus/MessageBus.h"
#include "../MessageBus/DataBuffer.h"

// GameConsole class intended to allow game debug input to MessageBus
// User/Developer types game engine messages into console, and these messages are then used in the game

// Console will need to use menu system, drop-down menu, or implement some form of window inside of the game window (similar to Source engine console)

namespace ge2d
{
class MessageBus;
class DataBuffer;

class GameConsoleSystem
{
public:

	GameConsoleSystem() {}
	~GameConsoleSystem() {}

	bool StartUp(MessageBus *initMessageBusPtr, DataBuffer *initDataBufferPtr);
	bool Shutdown();

public:

	MessageBus *messageBusPtr;
	DataBuffer *dataBufferPtr;

};

}	// namespace ge2d