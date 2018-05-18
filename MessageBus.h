#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <functional>
#include <queue>
#include <vector>

#include <SDL/SDL.h>

#include "Message.h"
#include "MessageMouse.h"
#include "MessageKeyboard.h"

namespace Cagan
{

	class IMessageReceiver;

	class MessageBus
	{
		public:
			MessageBus();
			virtual ~MessageBus();
			void addReceiver(IMessageReceiver* messageReceiver);
			void sendMessage(Message* message);
			void notify();

		protected:

		private:
			std::vector<IMessageReceiver*> receivers;
			std::queue<Message*> messages;
	};

	// Base class
	class IMessageReceiver
	{
	   public:

		  virtual void handleMessage(Message* message) = 0;

	   protected:
		  IMessageReceiver(MessageBus* messageBus)
		  {
			  m_messageBus = messageBus;
			  m_messageBus->addReceiver(this);
		  }

		  void sendMessage(Message* message)
		  {
			  m_messageBus->sendMessage(message);
		  }

	   private:

		MessageBus* m_messageBus;


	};

}
#endif // MESSAGEBUS_H
