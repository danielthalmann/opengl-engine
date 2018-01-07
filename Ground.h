#ifndef GROUND_H
#define GROUND_H


class Ground
{
    public:
        Ground();
        virtual ~Ground();
        void setSummitHeight(float x, float y, float height);


    protected:
        float ** m_summits;
        int m_width;
        int m_height;

    private:
};

#endif // GROUND_H
