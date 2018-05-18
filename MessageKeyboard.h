#ifndef MESSAGEKEYBOARD_H
#define MESSAGEKEYBOARD_H

#include <SDL/SDL.h>

#include "Message.h"

namespace Cagan
{

    class MessageKeyboard : public Message
    {
        public:
            MessageKeyboard(EventType event, SDLKey key) : Message(event){ m_Key = key; }
            //virtual ~MessageKeyboard(){}
            SDLKey GetKey() { return m_Key; }

        protected:
            SDLKey m_Key;

        private:
    };

}
#endif // MESSAGEKEYBOARD_H
