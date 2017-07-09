// RenderSystem.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../MessageBus/MessageBus.h"
#include "../MessageBus/DataBuffer.h"

namespace ge2d
{
class MessageBus;
class DataBuffer;

class RenderSystem
{
public:

	RenderSystem() {}
	~RenderSystem() {}

	bool StartUp();
	bool Shutdown();

	void CreateWindow();
	void Draw();
	bool HandleMessage(EngineMessage *message);

public:

	int windowWidth;
	int windowHeight;
	sf::RenderWindow window;

public:

	MessageBus *messageBusPtr;
	DataBuffer *dataBufferPtr;
};


}