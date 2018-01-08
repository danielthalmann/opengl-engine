#include "Ground.h"

using namespace Cagan;

Ground::Ground(int x, int y)
{
    m_width = x;
    m_height = y;

    /* Allocation dynamique */
    m_summits = new float* [ m_height ];
    for (int i=0; i < m_height; i++)
        m_summits[i] = new float[ m_width ];

    /* Initialisation */
    for (int i=0; i < m_height; i++)
        for (int j=0; j < m_width; j++)
            m_summits[i][j] = 0.0;

}

Ground::~Ground()
{
    //dtor
}


/** \brief Défini la hauteur du sol
 *
 * \param x int
 * \param y int
 * \param height float
 * \return void
 *
 */
void Ground::setSummitHeight(int x, int y, float height)
{

}


/** \brief dessine le sol
 *
 * \return void
 *
 */
void Ground::draw()
{

    glBegin(GL_QUADS);
    glColor3ub(0,255,0); //face verte

    /* Initialisation */
    for (int i=0; i < m_height- 1; i++)
        for (int j=0; j < m_width - 1; j++){
            glVertex3d(j  ,i  ,m_summits[i][j]);
            glVertex3d(j+1,i  ,m_summits[i][j]);
            glVertex3d(j+1,i+1,m_summits[i][j]);
            glVertex3d(j  ,i+1,m_summits[i][j]);
        }

    glEnd();

}
