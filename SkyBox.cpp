#include "SkyBox.h"

using namespace Cagan;

SkyBox::SkyBox()
{
    m_width = 100.0;
    m_height = 50.0;
}

SkyBox::~SkyBox()
{
    //dtor
}

void SkyBox::init()
{
    m_Textures[0] = loadTexture("textures\\Front.bmp");
    m_Textures[1] = loadTexture("textures\\Left.bmp");
    m_Textures[2] = loadTexture("textures\\Back.bmp");
    m_Textures[3] = loadTexture("textures\\Right.bmp");
    m_Textures[4] = loadTexture("textures\\Top.bmp");
}

void SkyBox::draw()
{

    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);

    glTranslatef(m_Position.x, m_Position.y, m_Position.z + (m_height / 2));

    glColor4ub(255,255,255,128);

    for (int i = 0; i < 4; i++)
    {
        glBindTexture(GL_TEXTURE_2D, m_Textures[i]);

        glBegin(GL_QUADS);
            glTexCoord2d(0,1);
            glVertex3d(m_width+.5,m_width,m_height);
            glTexCoord2d(0,0);
            glVertex3d(m_width+.5,m_width,-m_height);
            glTexCoord2d(1,0);
            glVertex3d(-m_width-.5,m_width,-m_height);
            glTexCoord2d(1,1);
            glVertex3d(-m_width-.5,m_width,m_height);
        glEnd();

        glRotated(90,0,0,1);
    }

    glBindTexture(GL_TEXTURE_2D, m_Textures[4]);

     glBegin(GL_QUADS);
    glTexCoord2d(0,1);
    glVertex3d(m_width+.5,-m_width,m_height-.5);
    glTexCoord2d(0,0);
    glVertex3d(m_width+.5,m_width,m_height-.5);
    glTexCoord2d(1,0);
    glVertex3d(-m_width-.5,m_width,m_height-.5);
    glTexCoord2d(1,1);
    glVertex3d(-m_width-.5,-m_width,m_height-.5);
    glEnd();


    glPopAttrib();
    glPopMatrix();

}

void SkyBox::update(unsigned int ellapsed_time)
{

}

void SkyBox::handleMessage(Message* message)
{
    switch(message->getEvent())
    {
		case EventType::CAMERAMOVE:
			m_Position = ((MessagePosition*)message)->getPosition();
			break;
    }
}

