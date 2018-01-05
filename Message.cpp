#include "Message.h"

using namespace Cagan;

Message::Message(EventType event)
{
    m_event = event;
}

EventType Message::getEvent()
{
    return m_event;
}
Message::~Message()
{
    //dtor
}
