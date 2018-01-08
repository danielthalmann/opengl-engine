#include "Ground.h"

using namespace Cagan;

Ground::Ground(int x, int y)
{
    m_width = x;
    m_height = y;

    /* Allocation dynamique */
    m_summits = new float* [ m_height ];
    for (int i=0; i < m_height; i++)
        t[i] = new float[ m_width ];

    /* Initialisation */
    for (int i=0; i < m_height; i++)
        for (int j=0; j < m_width; j++)
            m_summits[i][j] = 0.0;

}

Ground::~Ground()
{
    //dtor
}

Ground::setSummitHeight(int x, int y, float height)
{

}
