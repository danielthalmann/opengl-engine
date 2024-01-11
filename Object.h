#ifndef OBJECT_H
#define OBJECT_H

#include "sdlglutils.h"

#include "vector.h"

namespace Cagan
{

    class Object
    {
        public:
            Object();
            virtual ~Object();

            virtual void draw(){};
            virtual void update(__attribute__((unused)) unsigned int ellapsed_time){};
            virtual void init(){};
            virtual void setPosition(V3f position){ m_Position = position; };

        protected:

            V3f m_Position;

            float m_phi;
            float m_theta;

            unsigned int m_Texture;

        private:
    };

}

#endif // OBJECT_H
