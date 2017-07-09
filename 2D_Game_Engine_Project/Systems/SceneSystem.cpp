// SceneSystem.cpp
#include "SceneSystem.h"
using namespace ge2d;


bool SceneSystem::StartUp(MessageBus *initMessageBusPtr, DataBuffer *initDataBufferPtr)
{
	if (initMessageBusPtr == NULL) {
		std::cout << "(SceneSystem::StartUp) Error: function received NULL MessageBusPtr." << std::endl;
		return false;
	}
	if (initDataBufferPtr == NULL) {
		std::cout << "(SceneSystem::StartUp) Error: function received NULL DataBufferPtr." << std::endl;
		return false;
	}

	messageBusPtr = initMessageBusPtr;
	dataBufferPtr = initDataBufferPtr;

	if (messageBusPtr == NULL) {
		std::cout << "(SceneSystem::StartUp) Error: messageBusPtr is NULL after assignment." << std::endl;
		return false;
	}
	if (dataBufferPtr == NULL) {
		std::cout << "(SceneSystem::StartUp) Error: dataBufferPtr is NULL after assignment." << std::endl;
		return false;
	}

	return true;
}

bool SceneSystem::Shutdown()
{
	return true;
}