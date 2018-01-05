#include <iostream>
#include "Console.h"

using namespace Cagan;

Console::Console(MessageBus* messageBus): IMessageReceiver(messageBus)
{
    //ctor
}

Console::~Console()
{
    //dtor
}
void Console::handleMessage(Message* message)
{
    switch(message->getEvent())
    {
		case EventType::MOUSEMOTION:
			std::cout << "MOUSEMOTION";
			break;
		case EventType::KEYDOWN:
			std::cout << "KEYDOWN";
			break;
		case EventType::KEYUP:
			std::cout << "KEYUP";
			break;
		case EventType::MOUSEBUTTONDOWN:
			std::cout << "MOUSEBUTTONDOWN";
			break;
		case EventType::MOUSEBUTTONUP:
			std::cout << "MOUSEBUTTONUP";
			break;
    };

    std::cout << "\n";
}
