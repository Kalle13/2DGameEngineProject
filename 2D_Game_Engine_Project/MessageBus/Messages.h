// Messages.h
#pragma once

// MessageType specifies the System that is meant to handle the message after it is sent
// Message macros could be defined for specific systems, but if a MessageType parameter is used, then all messages can be sent/received by any System
// Consider the utility of a 'MessageSender' parameter that defines the System that sent a message


typedef unsigned int GE2D_MESSAGE;

enum MessageType
{
	Test,
	GameConsole,
	UserInput
};

struct Message
{
	GE2D_MESSAGE message;
	MessageType messageType;
	unsigned* dataPointer;
};




/*----------------------------------- Message Macros -----------------------------------*/

#define GE2D_MESSAGE_TEST_SEND		0x0001
#define GE2D_MESSAGE_TEST_REPLY		0x0002

