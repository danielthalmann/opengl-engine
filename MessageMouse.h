#ifndef MESSAGEMOUSE_H
#define MESSAGEMOUSE_H

#include "Message.h"

namespace Cagan
{

    class MessageMouse : public Message
    {
        public:
            MessageMouse(EventType event, unsigned int x, unsigned int y): Message(event) { m_x = x; m_y = y; };
            MessageMouse(EventType event, unsigned int x, unsigned int y, unsigned int button): Message(event) { m_x = x; m_y = y; m_button = button; };

            unsigned int getX(){ return m_x; }
            unsigned int getY(){ return m_y; }
            unsigned int getButton(){ return m_button; }

        protected:
            unsigned int m_x;
            unsigned int m_y;
            unsigned int m_button;

        private:
    };

}
#endif // MESSAGEMOUSE_H
