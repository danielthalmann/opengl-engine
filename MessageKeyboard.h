#ifndef MESSAGEKEYBOARD_H
#define MESSAGEKEYBOARD_H

#include <SDL2/SDL.h>

#include "Message.h"

namespace Cagan
{

    class MessageKeyboard : public Message
    {
        public:
            MessageKeyboard(EventType event, SDL_Keycode key) : Message(event){ m_Key = key; }
            //virtual ~MessageKeyboard(){}
            SDL_Keycode GetKey() { return m_Key; }

        protected:
            SDL_Keycode m_Key;

        private:
    };

}
#endif // MESSAGEKEYBOARD_H
