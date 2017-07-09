// SceneSystem.h
#pragma once
#include "../MessageBus/MessageBus.h"

// SceneSystem used to store data for entities and level areas.
// SceneSystem Will likely contain EntityManager and LevelAreaManager for updating entities and level areas.
// SceneSystem may also send messages to RenderSyste, regarding what to entities/areas to render.
namespace ge2d
{
class MessageBus;

class SceneSystem
{
public:

	SceneSystem() {}
	~SceneSystem() {}

	bool StartUp();
	bool Shutdown();

public:

	MessageBus *messageBusPtr;
	DataBuffer *dataBufferPtr;

};

}	// namespace ge2d