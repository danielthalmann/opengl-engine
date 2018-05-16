#include "Ground.h"
#include <iostream>
#include <math.h>       /* cos */

using namespace Cagan;

Ground::Ground(int x, int y)
{
    m_time = 0;
    m_width = x;
    m_height = y;
    m_wireframe = false;

    /* Allocation dynamique */
    m_summits = new float* [ m_height ];
    for (int i=0; i < m_height; i++)
        m_summits[i] = new float[ m_width ];

    /* Initialisation */
    for (int i=0; i < m_height; i++)
        for (int j=0; j < m_width; j++)
            m_summits[i][j] = (j * 12);

}

Ground::~Ground()
{
    m_info = false;
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
    m_summits[x][y] = height;
}


/** \brief dessine le sol
 *
 * \return void
 *
 */
void Ground::draw()
{
    if(m_wireframe){
        // Turn on wireframe mode
        glPolygonMode(GL_FRONT, GL_LINE);
        glPolygonMode(GL_BACK, GL_LINE);
    }

    glBegin(GL_TRIANGLES);


    /* Initialisation */
    for (int i=0; i < m_height- 1; i++){

        for (int j=0; j < m_width - 1; j++){
                if(!m_info){
                        /*
                    std::cout << j << ",";
                    std::cout << i  << ",";
                    std::cout << m_summits[i][j];
                    std::cout << "\n";
                    */
                }
//             glColor3ub(0,255,(int)m_summits[i][j]); //face verte

            glVertex3d(j  ,i  ,cos(m_summits[i][j]));
            glVertex3d(j+1,i  ,cos(m_summits[i][j+1]));
            glVertex3d(j+1,i+1,cos(m_summits[i+1][j+1]));

            glVertex3d(j  ,i  ,cos(m_summits[i][j]));
            glVertex3d(j+1,i+1,cos(m_summits[i+1][j+1]));
            glVertex3d(j  ,i+1,cos(m_summits[i+1][j]));
        }
    }

    m_info = true;

    glEnd();

    if(m_wireframe){
        // Turn off wireframe mode
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);
    }

}

void Ground::update(float ellapsed_time)
{
        /* Initialisation */
        for (int i=0; i < m_height; i++)
            for (int j=0; j < m_width; j++)
                m_summits[i][j] += (1.0 / 400) * ellapsed_time;



}

