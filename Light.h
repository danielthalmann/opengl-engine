#ifndef LIGHT_H
#define LIGHT_H

#include "Object.h"

namespace Cagan
{

    class Light : public Object
    {
        public:
            Light();
            virtual ~Light();
            virtual void draw();


        protected:

            V4f m_Position;

        private:
    };

}

#endif // LIGHT_H
