#ifndef MESSAGEKEYBOARD_H
#define MESSAGEKEYBOARD_H

#include <SDL/SDL.h>

#include "Message.h"

namespace Cagan
{

    class MessageKeyboard : public Message
    {
        public:
            MessageKeyboard(EventType event, SDLKey key);
            virtual ~MessageKeyboard();

            SDLKey GetKey() { return m_Key; }

        protected:

        private:
            SDLKey m_Key;
    };

}
#endif // MESSAGEKEYBOARD_H
