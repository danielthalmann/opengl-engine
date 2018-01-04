#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
    public:
        Message(const std::string event);
        virtual ~Message();
        std::string getEvent();

    protected:

    private:
        std::string messageEvent;
};

#endif // MESSAGE_H
