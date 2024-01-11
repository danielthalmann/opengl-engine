#include <string>
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
    std::string name = ("planet");


    m_Textures[0] = loadTexture((std::string("textures\\skybox\\") + name + std::string("\\front.jpg")).c_str());
    m_Textures[1] = loadTexture((std::string("textures\\skybox\\") + name + std::string("\\left.jpg")).c_str());
    m_Textures[2] = loadTexture((std::string("textures\\skybox\\") + name + std::string("\\back.jpg")).c_str());
    m_Textures[3] = loadTexture((std::string("textures\\skybox\\") + name + std::string("\\right.jpg")).c_str());
    m_Textures[4] = loadTexture((std::string("textures\\skybox\\") + name + std::string("\\top.jpg")).c_str());;
    m_Textures[5] = loadTexture((std::string("textures\\skybox\\") + name + std::string("\\bottom.jpg")).c_str());
}

void SkyBox::draw()
{

    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);

    glTranslatef(m_Position.x, m_Position.y, m_Position.z + (m_height / 2));

    glColor4ub(255,255,255,128);

    float adjust = .4;

    for (int i = 0; i < 4; i++)
    {
        glBindTexture(GL_TEXTURE_2D, m_Textures[i]);

        glBegin(GL_QUADS);
            glTexCoord2d(0,1);
            glVertex3d(m_width+adjust,m_width,m_height);
            glTexCoord2d(0,0);
            glVertex3d(m_width+adjust,m_width,-m_height);
            glTexCoord2d(1,0);
            glVertex3d(-m_width-adjust,m_width,-m_height);
            glTexCoord2d(1,1);
            glVertex3d(-m_width-adjust,m_width,m_height);
        glEnd();

        glRotated(90,0,0,1);
    }

    for (int i = 0; i < 2; i++)
    {

        glBindTexture(GL_TEXTURE_2D, m_Textures[4 + i]);

        glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(m_width+adjust,-m_width-adjust,m_height-adjust);
        glTexCoord2d(0,0);
        glVertex3d(m_width+adjust,m_width+adjust,m_height-adjust);
        glTexCoord2d(1,0);
        glVertex3d(-m_width-adjust,m_width+adjust,m_height-adjust);
        glTexCoord2d(1,1);
        glVertex3d(-m_width-adjust,-m_width+adjust,m_height-adjust);
        glEnd();

        glRotated(180,1,0,0);

    }

    glPopAttrib();
    glPopMatrix();

}

void SkyBox::update(__attribute__((unused)) unsigned int ellapsed_time)
{

}

void SkyBox::handleMessage(Message* message)
{
    switch(message->getEvent())
    {
		case EventType::CAMERAMOVE:
			m_Position = ((MessagePosition*)message)->getPosition();
			break;
		default:
			break;
    }
}

