#include "MessageKeyboard.h"

using namespace Cagan;

MessageKeyboard::MessageKeyboard(EventType event, SDLKey key) : Message(event)
{
    m_Key = key;
}

MessageKeyboard::~MessageKeyboard()
{
    //dtor
}
