// GameEngine.h
#pragma once

#include "../MessageBus/MessageBus.h"
#include "../MessageBus/Messages.h"
#include "../MessageBus/DataBuffer.h"
#include "../Systems/InputSystem.h"
#include "../Systems/GameConsole.h"

namespace ge2d
{
class MessageBus;
class InputSystem;
class GameConsole;

class GameEngine
{
public:

	GameEngine() {}
	~GameEngine() {}

	bool StartUp();
	bool ShutDown();

public:

	MessageBus *messageBusPtr;
	InputSystem *inputSystemPtr;
	GameConsole *gameConsolePtr;

};


} // namespace ge2d