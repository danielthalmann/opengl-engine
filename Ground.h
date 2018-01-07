#ifndef GROUND_H
#define GROUND_H


namespace Cagan
{

    class Ground
    {
        public:
            Ground(int x, int y);
            virtual ~Ground();
            void setSummitHeight(int x, int y, float height);


        protected:
            float ** m_summits;
            int m_width;
            int m_height;

        private:
    };
}

#endif // GROUND_H
