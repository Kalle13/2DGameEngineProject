// RenderSystem.cpp

#include "RenderSystem.h"
using namespace ge2d;

bool RenderSystem::StartUp()
{
	windowWidth = 800;
	windowHeight = 600;
	return true;
}

bool RenderSystem::Shutdown()
{
	return true;
}

void RenderSystem::CreateWindow()
{
	sf::VideoMode videoMode(windowWidth, windowHeight);
	window.create(videoMode, "game window");
}

void RenderSystem::Draw()
{

}

bool RenderSystem::HandleMessage(EngineMessage *message)
{
	bool messageHandled = false;

	EngineMessage receivedMessage = *message;

	switch (receivedMessage.message)
	{
	case ge2d::TestSend:

		break;
	default:
		std::cout << "(RenderSystem::HandleMessage) No handler for message: " << message->message << std::endl;
		break;
	}

	return messageHandled;
}