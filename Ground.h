#ifndef GROUND_H
#define GROUND_H

#include <GL/gl.h>
#include <GL/glu.h>


namespace Cagan
{

    class Ground
    {
        public:
            Ground(int x, int y);
            virtual ~Ground();
            void setSummitHeight(int x, int y, float height);
            void draw();


        protected:
            float ** m_summits;
            int m_width;
            int m_height;
            bool m_info;

        private:
    };
}

#endif // GROUND_H
