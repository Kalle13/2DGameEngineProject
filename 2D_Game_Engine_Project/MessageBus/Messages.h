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
	Render
};

// messages that are sent by systems
enum SystemMessages
{

// Test System messages
	TestSend = 0,
	TestReply,

// Input System messages
	// Received by Input System
	InputRead,
	InputRemap,

	// Sent from Input System
	InputKeyPressed,
	InputKeyReleased,
	InputKeyEdgeRising,
	InputKeyEdgeFalling,
	InputMouseEvent,
	InputJoystickEvent,

	Count	// Total number of GE2D messages
};

// dataPointer should point to some memory address on the heap (slow, but predictable)
// The data associated with a message will be stored using the DataBuffer (it may be easier 
// to just have the data sent with the message, or stored somewhere in the MessageBus,
// memory block, as decided by the MesageBus).
struct EngineMessage
{
	SystemMessages message;
	unsigned* dataPtr;
	//MessageSource messageSource;

	EngineMessage() {}
	EngineMessage(SystemMessages iMessage, unsigned* iDataPtr) : message(iMessage), dataPtr(iDataPtr) {}

	friend std::ostream& operator<<(std::ostream& os, const EngineMessage& engineMessage)
	{
		os << engineMessage.message << "\t" << engineMessage.dataPtr << " ";
		return os;
	}
};

}	// namespace ge2d