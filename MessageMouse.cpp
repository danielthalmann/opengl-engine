#include "MessageMouse.h"

using namespace Cagan;

MessageMouse::MessageMouse(EventType event, unsigned int x, unsigned int y) : Message(event)
{
    m_x = x;
    m_y = y;
}
MessageMouse::MessageMouse(EventType event, unsigned int x, unsigned int y, unsigned int button) : Message(event)
{
    m_x = x;
    m_y = y;
    m_button = button;
}


MessageMouse::~MessageMouse()
{
    //dtor
}

unsigned int MessageMouse::getX()
{
    return m_x;
}
unsigned int MessageMouse::getY()
{
    return m_y;
}
unsigned int MessageMouse::getButton()
{
    return m_button;
}

