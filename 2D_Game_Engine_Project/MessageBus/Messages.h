// Messages.h
#pragma once

namespace ge2d
{
	// Do not send a MessageSource enumeration with a Message; the 
	// "Messages" enum already specifies the source.
	// Knowing the message source may help with interpreting data sent by a System.
enum MessageSource
{
	Test = 0,
	GameConsole,
	Input,
	Render,
	Scene
};

// messages that are sent by systems
enum SystemMessages
{

// Test System messages
	TestSend = 0,
	TestReply,

// Input System messages
	// Received by Input System
	InputRead,			// Used to tell input system to read inputs
	InputRemap,			// Used to remap an SFML event to an input message
	InputDisable,		// Used to disable an input type (e.g. disable the mouse)
	// Sent from Input System
	InputKeyPressed,
	InputKeyReleased,
	InputKeyEdgeRising,
	InputKeyEdgeFalling,
	InputMouseEvent,
	InputJoystickEvent,

// Render System messages
	//Received
	RenderCreateWindow,	
	RenderUpdateWindow,	// Update the window size, position, etc.
	RenderDraw,			// Draw everything (game objects) to window
	//Sent

	Count	// Total number of GE2D messages
};

// dataPointer should point to some memory address on the heap (slow, but predictable)
// The data associated with a message will be stored using the DataBuffer (it may be easier 
// to just have the data sent with the message, or stored somewhere in the MessageBus,
// memory block, as decided by the MesageBus).
struct EngineMessage
{
	unsigned* dataPtr;
	SystemMessages message;
	char padding[4];

	EngineMessage() {}
	EngineMessage(SystemMessages iMessage) : message(iMessage), dataPtr(NULL) {}
	EngineMessage(SystemMessages iMessage, unsigned* iDataPtr) : message(iMessage), dataPtr(iDataPtr) {}

	friend std::ostream& operator<<(std::ostream& os, const EngineMessage& engineMessage)
	{
		os << engineMessage.message << "\t" << engineMessage.dataPtr << " ";
		return os;
	}
};

}	// namespace ge2d