#include "MessageBus.h"

using namespace Cagan;

MessageBus::MessageBus()
{
    //ctor
}

MessageBus::~MessageBus()
{
    //dtor
}

void MessageBus::addReceiver(IMessageReceiver* messageReceiver)
{
    receivers.push_back(messageReceiver);
}

void MessageBus::sendMessage(Message* message)
{
    messages.push(message);
}

void MessageBus::notify()
{

	//
	// récupère en premier lieu les événements SDL
	//
    SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{

		case SDL_MOUSEBUTTONDOWN:
			this->sendMessage(new Cagan::MessageMouse(Cagan::EventType::MOUSEBUTTONDOWN, event.motion.x, event.motion.y, event.button.button));
			break;

		case SDL_MOUSEBUTTONUP:
			this->sendMessage(new Cagan::MessageMouse(Cagan::EventType::MOUSEBUTTONUP, event.motion.x, event.motion.y, event.button.button));
			break;

		case SDL_MOUSEMOTION:
			this->sendMessage(new Cagan::MessageMouse(Cagan::EventType::MOUSEMOTION, event.motion.x, event.motion.y));
			break;

		case SDL_KEYDOWN:
			this->sendMessage(new Cagan::MessageKeyboard(Cagan::EventType::KEYDOWN, event.key.keysym.sym));
			break;

		case SDL_KEYUP:
			this->sendMessage(new Cagan::MessageKeyboard(Cagan::EventType::KEYUP, event.key.keysym.sym));
			break;

		case SDL_QUIT:
			exit(0);
			break;
		}

	}

    while(!messages.empty()) {
        for (std::vector<IMessageReceiver*>::iterator iter = receivers.begin(); iter != receivers.end(); iter++) {
            (*iter)->handleMessage(messages.front());
        }

        messages.pop();
    }
}
