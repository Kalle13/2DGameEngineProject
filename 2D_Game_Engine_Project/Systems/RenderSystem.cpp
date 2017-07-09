// RenderSystem.cpp

#include "RenderSystem.h"
using namespace ge2d;

bool RenderSystem::StartUp(MessageBus *initMessageBusPtr, DataBuffer *initDataBufferPtr)
{

	if (initMessageBusPtr == NULL) {
		std::cout << "(TestSystem::StartUp) Error: function received NULL MessageBusPtr." << std::endl;
		return false;
	}
	if (initDataBufferPtr == NULL) {
		std::cout << "(TestSystem::StartUp) Error: function received NULL DataBufferPtr." << std::endl;
		return false;
	}

	messageBusPtr = initMessageBusPtr;
	dataBufferPtr = initDataBufferPtr;

	if (messageBusPtr == NULL) {
		std::cout << "(TestSystem::StartUp) Error: messageBusPtr is NULL after assignment." << std::endl;
		return false;
	}
	if (dataBufferPtr == NULL) {
		std::cout << "(TestSystem::StartUp) Error: dataBufferPtr is NULL after assignment." << std::endl;
		return false;
	}

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