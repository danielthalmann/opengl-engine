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
            void update(unsigned int ellapsed_time);


        protected:

            V4f m_Ambient;
            V4f m_Diffuse;
            V4f m_Specular;

        private:
    };

}

#endif // LIGHT_H
