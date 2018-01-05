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
	// r�cup�re en premier lieu les �v�nements SDL
	//
    SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{

		case SDL_MOUSEBUTTONDOWN:
			this->sendMessage(new Cagan::Message(Cagan::EventType::MOUSEBUTTONDOWN));
			break;

		case SDL_MOUSEBUTTONUP:
			this->sendMessage(new Cagan::Message(Cagan::EventType::MOUSEBUTTONUP));
			break;

		case SDL_MOUSEMOTION:
			this->sendMessage(new Cagan::Message(Cagan::EventType::MOUSEMOTION));
			break;

		case SDL_KEYDOWN:
			this->sendMessage(new Cagan::Message(Cagan::EventType::KEYDOWN));
			break;

		case SDL_KEYUP:
			this->sendMessage(new Cagan::Message(Cagan::EventType::KEYUP));
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
