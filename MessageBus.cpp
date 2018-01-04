
#include "MessageBus.h"

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
    while(!messages.empty()) {
        for (std::vector<IMessageReceiver*>::iterator iter = receivers.begin(); iter != receivers.end(); iter++) {
            (*iter)->handleMessage(messages.front());
        }

        messages.pop();
    }
}
