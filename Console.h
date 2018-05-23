#ifndef CONSOLE_H
#define CONSOLE_H

#include <SDL2/SDL.h>

#include "IMessageReceiver.h"

namespace Cagan
{

	class Console : public IMessageReceiver
	{
		public:
			Console();
			virtual ~Console();

			void handleMessage(Message* message);

		protected:

		private:
	};

}
#endif // CONSOLE_H
