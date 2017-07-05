// GameEngine2D pseudocode
// InputSystem.h
// pseudocode for InputSystem class

#pragma once
#include "MessageBus.h"


namespace ge2d
{
	class InputSystem
	{
	public:
			
			InputSystem() {}
			~InputSystem() {}
			
			bool StartUp();
			bool ShutDown();
			
			// MessageBus functions
			bool HandleMessage(GE2D_MESSAGE *message);
			
			// Input Map Initialization functions (can get rid of these if too slow; initialize all maps in StartUp())
			bool InitKeyboardToMessageMap();
			bool InitMouseToMessageMap();
			bool InitControllerToMessageMap();
			
			// Configure Input Map Functions (to be used via messages from Game/GameLogic class)
			bool ConfigureKeyboardToMessageMap();
			bool ConfigureMouseToMessageMap();
			bool ConfigureControllerToMessageMap();
			
			// Read inputs
			bool ReadKeyBoardInput();
			bool ReadMouseInput();
			bool ReadJoystickInput();
			
	public:

			MessageBus *messageBusPtr;
			RenderSystem *renderSystemPtr;	// RenderSystem dependency (needed for access to game window, an sf::RenderWindow)
			
			// maps to determine the messages to be sent to message bus when the corresponding input is used
			ge2dMap keyboardInputToMessageMap;
			ge2dMap mouseInputToMessageMap;
			ge2dMap controllerInputToMessageMap;
			
			
	}
}

// GameEngine2D pseudocode
// InputSystem.cpp
#include "InputSystem.h"
#include "RenderSystem.h"

extern gRenderSystem;

using namespace ge2d
{

bool InputSystem::StartUp()
{
	InitKeyboardToMessageMap();
	InitMouseToMessageMap();
	InitControllerToMessageMap();
}


bool InputSystem::ShutDown()
{
	
}



bool InputSystem::HandleMessage(GE2D_MESSAGE *message)
{
	switch(message->message)
	{
		
	}
}


bool InputSystem::InitKeyboardToMessageMap()
{
	
}

bool InputSystem::InitMouseToMessageMap()
{
	
}

bool InputSystem::InitControllerToMessageMap()
{
	
}


bool InputSystem::ReadKeyBoardInput()
{
	
}

bool InputSystem::ReadMouseInput()
{
	
}

bool InputSystem::ReadJoystickInput()
{
	
}