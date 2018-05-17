#ifndef OBJECT_H
#define OBJECT_H

namespace Cagan
{

    class Object
    {
        public:
            Object();
            virtual ~Object();

            virtual void draw();
            virtual void update(unsigned int ellapsed_time);

        protected:

        private:
    };

}

#endif // OBJECT_H
