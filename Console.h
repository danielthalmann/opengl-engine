#ifndef CONSOLE_H
#define CONSOLE_H

#include <SDL/SDL.h>

#include "MessageBus.h"

namespace Cagan
{

	class Console : public IMessageReceiver
	{
		public:
			Console(MessageBus* messageBus);
			virtual ~Console();

			void handleMessage(Message* message);

		protected:

		private:
	};

}
#endif // CONSOLE_H
