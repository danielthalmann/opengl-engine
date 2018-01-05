#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

namespace Cagan
{
	enum EventType {
		MOUSEMOTION,
		KEYDOWN,
		KEYUP,
		MOUSEBUTTONDOWN,
		MOUSEBUTTONUP
	};

	class Message
	{
		public:
			Message(EventType event);
			virtual ~Message();
			EventType getEvent();

		protected:

		private:
			EventType m_event;
	};
}

#endif // MESSAGE_H
