#ifndef MESSAGEMOUSE_H
#define MESSAGEMOUSE_H

#include "Message.h"

namespace Cagan
{

    class MessageMouse : public Message
    {
        public:
            MessageMouse(EventType event, unsigned int x, unsigned int y);
            MessageMouse(EventType event, unsigned int x, unsigned int y, unsigned int button);
            virtual ~MessageMouse();

            unsigned int getX();
            unsigned int getY();
            unsigned int getButton();

        protected:
            unsigned int m_x;
            unsigned int m_y;
            unsigned int m_button;

        private:
    };

}
#endif // MESSAGEMOUSE_H
