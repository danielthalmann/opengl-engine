#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"

namespace Cagan
{

    class Object
    {
        public:
            Object();
            virtual ~Object();

            virtual void draw(){};
            virtual void update(unsigned int ellapsed_time){};
            virtual void init(){};

        protected:

            V3f m_Position;

        private:
    };

}

#endif // OBJECT_H
