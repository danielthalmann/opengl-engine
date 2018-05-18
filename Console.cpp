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
			std::cout << "MOUSEMOTION X:" << ((MessageMouse*)message)->getX() << " y:" << ((MessageMouse*)message)->getY();
			break;
		case EventType::KEYDOWN:
			std::cout << "KEYDOWN" << ((MessageKeyboard*)message)->GetKey();
			break;
		case EventType::KEYUP:
			std::cout << "KEYUP";
			switch(((MessageKeyboard*)message)->GetKey()){
                case SDLK_a:
                    std::cout << " A";
                case SDLK_UP:
                    std::cout << " ^";
                break;
			}
			break;
		case EventType::MOUSEBUTTONDOWN:
		    std::cout << "MOUSEBUTTONDOWN X:" << ((MessageMouse*)message)->getX() << " y:" << ((MessageMouse*)message)->getY() << " Button:" << ((MessageMouse*)message)->getButton();
			break;
		case EventType::MOUSEBUTTONUP:
		    std::cout << "MOUSEBUTTONUP X:" << ((MessageMouse*)message)->getX() << " y:" << ((MessageMouse*)message)->getY() << " Button:" << ((MessageMouse*)message)->getButton();
			break;
    };

    std::cout << "\n";
}


