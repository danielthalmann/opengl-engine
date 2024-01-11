#ifndef MESSAGEPOSITION_H
#define MESSAGEPOSITION_H

#include "Message.h"
#include "vector.h"

namespace Cagan
{

    class MessagePosition : public Message
    {
        public:
            MessagePosition(EventType event, V3f position): Message(event) { m_Position = position; };

            V3f getPosition(){ return m_Position; }

        protected:
            V3f m_Position;

        private:
    };

}
#endif // MESSAGEPOSITION_H
