#include "Ground.h"
#include <iostream>
#include <math.h>       /* cos */

using namespace Cagan;

Ground::Ground(int x, int y) : Object()
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

    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);

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



            V4f v1(j  ,i  ,cos(m_summits[i][j]));
            V4f v2(j+1,i  ,cos(m_summits[i][j+1]));
            V4f v3(j+1,i+1,cos(m_summits[i+1][j+1]));
            V4f v4(j  ,i+1,cos(m_summits[i+1][j]));

            glVertex3f(v1.x, v1.y, v1.z);
            glNormal3fv(v1.Cross(v3).getTable());
            glVertex3f(v2.x, v2.y, v2.z);
            glNormal3fv(v1.Cross(v3).getTable());
            glVertex3f(v3.x, v3.y, v3.z);
            glNormal3fv(v1.Cross(v3).getTable());


            glVertex3f(v1.x, v1.y, v1.z);
            glNormal3fv(v1.Cross(v3).getTable());
            glVertex3f(v3.x, v3.y, v3.z);
            glNormal3fv(v1.Cross(v3).getTable());
            glVertex3f(v4.x, v4.y, v4.z);
            glNormal3fv(v1.Cross(v3).getTable());
        }
    }

    m_info = true;

    glEnd();

    if(m_wireframe){
        // Turn off wireframe mode
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);
    }

    glPopAttrib();
    glPopMatrix();

}

void Ground::update(__attribute__((unused)) unsigned int ellapsed_time)
{

        /* Initialisation */
    /*
        for (int i=0; i < m_height; i++)
            for (int j=0; j < m_width; j++)
                m_summits[i][j] += (1.0 / 400) * ellapsed_time;
*/


}

