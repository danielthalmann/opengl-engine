#include "Message.h"

Message::Message(const std::string event)
{
    messageEvent = event;
}

std::string Message::getEvent()
{
    return messageEvent;
}
Message::~Message()
{
    //dtor
}
