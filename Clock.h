#ifndef CLOCK_H
#define CLOCK_H

#include <SDL2/SDL.h>

namespace Cagan
{
    class Clock
    {
        public:
            Clock();
            virtual ~Clock();

            unsigned int getEllapsed();

        protected:


            unsigned int last_time;
            unsigned int current_time;
            unsigned int ellapsed_time;


        private:
    };
}
#endif // CLOCK_H
