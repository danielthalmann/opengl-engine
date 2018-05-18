#ifndef IMESSAGERECEIVER_H
#define IMESSAGERECEIVER_H

#include "MessageBus.h"

namespace Cagan
{

	// Base class
	class IMessageReceiver
	{
	   public:

		  virtual void handleMessage(Message* message) = 0;

		  void setMessageBus(MessageBus* messageBus){
		      m_messageBus = messageBus;
		  }

	   protected:

	       MessageBus* m_messageBus;

	   private:

	};


}
#endif // IMESSAGERECEIVER_H
