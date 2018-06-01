#ifndef MESSAGEPOSITION_H
#define MESSAGEPOSITION_H

#include "Message.h"
#include "vector.h"

namespace Cagan
{

    class MessagePosition : public Message
    {
        public:
            MessagePosition(EventType event, V4f position): Message(event) { m_Position = position; };

            V4f getPosition(){ return m_Position; }

        protected:
            V4f m_Position;

        private:
    };

}
#endif // MESSAGEPOSITION_H
