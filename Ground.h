#ifndef GROUND_H
#define GROUND_H

#include <GL/gl.h>
#include <GL/glu.h>

#include <vector.h>
#include "Object.h"

namespace Cagan
{

    class Ground: public Object
    {
        public:
            Ground(int x, int y);
            virtual ~Ground();
            void setSummitHeight(int x, int y, float height);
            void draw();
            void update(unsigned int ellapsed_time);


        protected:
            float ** m_summits;
            int m_width;
            int m_height;
            bool m_info;
            float m_time;
            bool m_wireframe;

        private:
    };
}

#endif // GROUND_H
