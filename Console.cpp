#include <iostream>
#include "Console.h"

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
    std::cout << (message->getEvent()) << "\n";

}
