#ifndef CONSOLE_H
#define CONSOLE_H

#include "MessageBus.h"


class Console : public IMessageReceiver
{
    public:
        Console(MessageBus* messageBus);
        virtual ~Console();

        void handleMessage(Message* message);

    protected:

    private:
};

#endif // CONSOLE_H