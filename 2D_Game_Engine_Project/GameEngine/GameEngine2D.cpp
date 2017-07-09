// GameEngine.cpp
#include "GameEngine2D.h"
using namespace ge2d;

MessageBus gMessageBus;
DataBuffer gDataBuffer;
RenderSystem gRenderSystem;
InputSystem gInputSystem;
SceneSystem gSceneSystem;
GameConsoleSystem gGameConsoleSystem;
TestSystem gTestSystem;

bool GameEngine2D::StartUp()
{
	// Assign global Systems to game engine's system pointers
	engineMessageBusPtr = &gMessageBus;
	engineDataBufferPtr = &gDataBuffer;
	engineRenderSystemPtr = &gRenderSystem;
	engineInputSystemPtr = &gInputSystem;
	engineSceneSystemPtr = &gSceneSystem;
	engineTestSystemPtr = &gTestSystem;
	engineGameConsoleSystemPtr = &gGameConsoleSystem;

	// Assign dataBufferPtr to all game engine Systems
	engineMessageBusPtr->dataBufferPtr = engineDataBufferPtr;

	// Initialize all engine Systems
	// TODO: Implement error checking for each system as they are initialized
	unsigned maxMessageBusMessages = 100;
	engineMessageBusPtr->StartUp(maxMessageBusMessages);
	engineDataBufferPtr->StartUp();
	engineRenderSystemPtr->StartUp(engineMessageBusPtr,engineDataBufferPtr);
	engineInputSystemPtr->StartUp(engineMessageBusPtr, engineDataBufferPtr, engineRenderSystemPtr);
	engineSceneSystemPtr->StartUp(engineMessageBusPtr, engineDataBufferPtr);
	engineTestSystemPtr->StartUp(engineMessageBusPtr, engineDataBufferPtr);
	engineGameConsoleSystemPtr->StartUp(engineMessageBusPtr, engineDataBufferPtr);

	return true;
}

bool GameEngine2D::Shutdown()
{
	engineGameConsoleSystemPtr->Shutdown();
	engineTestSystemPtr->Shutdown();	
	engineSceneSystemPtr->Shutdown();
	engineInputSystemPtr->Shutdown();
	engineRenderSystemPtr->Shutdown();
	engineDataBufferPtr->Shutdown();
	engineMessageBusPtr->Shutdown();

	return true;
}