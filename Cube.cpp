#include "Cube.h"

using namespace Cagan;

Cube::Cube()
{
    m_angleZ = 0;
    m_angleX = 0;

}

Cube::~Cube()
{
    //dtor
}

void Cube::draw()
{

    glRotated(m_angleZ,0,0,1);

    glRotated(m_angleX,1,0,0);


    glBegin(GL_QUADS);


    glColor3ub(255,0,0); //face rouge

    glVertex3d(1,1,1);

    glVertex3d(1,1,-1);

    glVertex3d(-1,1,-1);

    glVertex3d(-1,1,1);


    glColor3ub(0,255,0); //face verte

    glVertex3d(1,-1,1);

    glVertex3d(1,-1,-1);

    glVertex3d(1,1,-1);

    glVertex3d(1,1,1);


    glColor3ub(0,0,255); //face bleue

    glVertex3d(-1,-1,1);

    glVertex3d(-1,-1,-1);

    glVertex3d(1,-1,-1);

    glVertex3d(1,-1,1);


    glColor3ub(255,255,0); //face jaune

    glVertex3d(-1,1,1);

    glVertex3d(-1,1,-1);

    glVertex3d(-1,-1,-1);

    glVertex3d(-1,-1,1);


    glColor3ub(0,255,255); //face cyan

    glVertex3d(1,1,-1);

    glVertex3d(1,-1,-1);

    glVertex3d(-1,-1,-1);

    glVertex3d(-1,1,-1);


    glColor3ub(255,0,255); //face magenta

    glVertex3d(1,-1,1);

    glVertex3d(1,1,1);

    glVertex3d(-1,1,1);

    glVertex3d(-1,-1,1);


    glEnd();

}

void Cube::update(unsigned int ellapsed_time)
{
    m_angleZ += 0.05 * ellapsed_time;
    m_angleX += 0.05 * ellapsed_time;
}
