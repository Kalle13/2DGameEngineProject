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
	engineMessageBusPtr = &gMessageBus;
	engineDataBufferPtr = &gDataBuffer;
	engineRenderSystemPtr = &gRenderSystem;
	engineInputSystemPtr = &gInputSystem;
	engineSceneSystemPtr = &gSceneSystem;
	engineTestSystemPtr = &gTestSystem;
	engineGameConsoleSystemPtr = &gGameConsoleSystem;

	// Assign dataBufferPtr to all game engine Systems
	engineMessageBusPtr->dataBufferPtr = engineDataBufferPtr;
	engineRenderSystemPtr->dataBufferPtr = engineDataBufferPtr;
	engineInputSystemPtr->dataBufferPtr = engineDataBufferPtr;
	engineSceneSystemPtr->dataBufferPtr = engineDataBufferPtr;
	engineTestSystemPtr->dataBufferPtr = engineDataBufferPtr;
	engineGameConsoleSystemPtr->dataBufferPtr = engineDataBufferPtr;

	// Assign messageBusPtr to all game engine Systems
	engineRenderSystemPtr->messageBusPtr = engineMessageBusPtr;
	engineInputSystemPtr->messageBusPtr = engineMessageBusPtr;
	engineSceneSystemPtr->messageBusPtr = engineMessageBusPtr;
	engineTestSystemPtr->messageBusPtr = engineMessageBusPtr;
	engineGameConsoleSystemPtr->messageBusPtr = engineMessageBusPtr;

	// Additional InputSystem assignments
	engineInputSystemPtr->renderSystemPtr = engineRenderSystemPtr;

	// Initialize all engine Systems
	unsigned maxMessageBusMessages = 100;
	engineMessageBusPtr->StartUp(maxMessageBusMessages);
	engineDataBufferPtr->StartUp();
	engineRenderSystemPtr->StartUp();
	engineInputSystemPtr->StartUp();
	engineSceneSystemPtr->StartUp();
	engineTestSystemPtr->StartUp();
	engineGameConsoleSystemPtr->StartUp();

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