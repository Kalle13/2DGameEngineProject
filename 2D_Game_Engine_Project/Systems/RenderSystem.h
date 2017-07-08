// RenderSystem.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../MessageBus/MessageBus.h"

namespace ge2d
{
class MessageBus;

class RenderSystem
{
public:

	RenderSystem() {}
	~RenderSystem() {}

	bool StartUp();
	bool ShutDown();

	void Draw();
	bool HandleMessage(EngineMessage *message);

public:

	MessageBus *messageBus;
};


}