// GameEngine.h
#pragma once

#include "../MessageBus/MessageBus.h"
#include "../MessageBus/Messages.h"
#include "../MessageBus/DataBuffer.h"
#include "../Systems/InputSystem.h"
#include "../Systems/GameConsoleSystem.h"
#include "../Systems/RenderSystem.h"
#include "../Systems/TestSystem.h"
#include "../Systems/SceneSystem.h"

namespace ge2d
{
class MessageBus;
class DataBuffer;
class InputSystem;
class GameConsoleSystem;
class RenderSystem;
class TestSystem;
class SceneSystem;

class GameEngine2D
{
public:

	GameEngine2D() {}
	~GameEngine2D() {}

	bool StartUp();
	bool Shutdown();

public:

	MessageBus *engineMessageBusPtr;
	DataBuffer *engineDataBufferPtr;
	RenderSystem *engineRenderSystemPtr;
	InputSystem *engineInputSystemPtr;
	SceneSystem *engineSceneSystemPtr;
	TestSystem *engineTestSystemPtr;
	GameConsoleSystem *engineGameConsoleSystemPtr;

};


} // namespace ge2d