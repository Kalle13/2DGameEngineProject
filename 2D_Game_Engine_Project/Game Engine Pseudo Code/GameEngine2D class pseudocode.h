// GameEngine2D pseudocode
// GameEngine2D.h
// pseudocode for top-level game engine class

#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "InputSystem.h"
#include "RenderSystem.h"
#include "AudioSystem.h"


namespace ge2d
{
	
class MessageBus;
class RenderSystem;
class InputSystem;
class SceneSystem;
class AudioSystem;
	
	
class GameEngine2D
{
public:

		GameEngine2D() {}
		~GameEngine2D() {}
		
		
		bool StartUp();
		bool ShutDown();
		
public:

		MessageBusPtr		*messageBus;
		InputSystemPtr		*inputSystem;
		SceneSystemPtr		*sceneSystem;
		RenderSystemPtr		*renderSystem;
		AudioSystemPtr		*audioSystem;
		
}

} // namespace ge2d


// GameEngine.cpp
// pseudocode for top-level game engine class

using namespace ge2d;

extern gMessageBus;
extern gInputSystem;
extern gRenderSystem;
extern gSceneSystem;
extern gAudioSystem;

bool GameEngine2D::StartUp()
{
	messageBusPtr = &gMessageBus;
	inputSystemPtr = &gInputSystem;
	sceneSystemPtr = &gSceneSystem;
	renderSystemPtr = &gRenderSystem;
	audioSystemPtr = &gAudioSystem;
	
	// Assign message bus address to system MessageBus pointers
	inputSystemPtr->messageBusPtr = &gMessageBus;
	sceneSystemPtr->messageBusPtr = &gMessageBus;
	renderSystemPtr->messageBusPtr = &gMessageBus;
	audioSystemPtr->messageBusPtr = &gMessageBus;
	
	// Initialize system dependencies
	inputSystemPtr->renderSystemPtr = &gRenderSystem;
	sceneSystemPtr->renderSystemPtr = &gSceneSystem;
	// Alternatively
	inputSystemPtr->renderSystemPtr = renderSystemPtr;
	sceneSystemPtr->renderSystemPtr = renderSystemPtr;
	
	messageBus->StartUp();
	inputSystem->StartUp();
	sceneSystem->StartUp();
	renderSystem->StartUp();
	audioSystem->StartUp();
	
}


bool GameEngine2D::ShutDown()
{
	messageBus->ShutDown();
	inputSystem->ShutDown();
	sceneSystem->ShutDown();
	renderSystem->ShutDown();
	audioSystem->ShutDown();
}




// main.cpp
// pseudocode for main function

// declare global systems
using namespace ge2d;	// use a namespace for the engine? (or don't, and keep it C-compatible)

// Declare global variables for the GameEngine2D's Systems.
// Make sure that each System constructor and destructor does not do anything.
// Initialization/shutdown will be performed with StartUp()/ShutDown() methods for each class.

ge2d::GameEngine2D 	gGameEngine2D;
ge2d::MessageBus	gMessageBus;
ge2d::InputSystem	gInputSystem;
ge2d::RenderSystem	gRenderSystem;
ge2d::SceneSystem	gSceneSystem;
ge2d::AudioSystem	gAudioSystem;

int main(){
	
	gGameEngine2D.StartUp();
	
	Game game();
	game.Run();
	
	gGameEngine2D.ShutDown();
	
	return 0;
}