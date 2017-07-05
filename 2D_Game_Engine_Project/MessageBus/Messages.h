// Messages.h
#pragma once

typedef unsigned int GE2D_MESSAGE;

namespace ge2d
{
// enum to let other Systems know which System sent the message
// May help with interpreting data sent by a System
enum MessageSource
{
	Test = 0,
	GameConsole,
	Input,
	Render
};

// messages that are sent by systems
enum GE2DMessage
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
struct Message
{
	GE2D_MESSAGE message;
	unsigned* dataPointer;
	MessageSource messageSource;
};

}	// namespace ge2d