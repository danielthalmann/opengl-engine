#include "Camera.h"


using namespace Cagan;

const float M_PI = 3.14;

Camera::Camera()
{
    m_Position = V3f(3.0, 0.0, 0.0);
	m_View =     V3f(0.0, 0.0, 0.0);
	m_UpVector = V3f(0.0, 0.0, 1.0);

    m_Up = false;
    m_Down = false;
    m_Left = false;
    m_Right = false;

    m_Climb = false;
    m_Crouch = false;

    m_CaptureMouse = false;

    m_speed = 0.005;

    m_phi = 0.0;
    m_theta = 180.0;
    turnCamera(0.0, 0.0);

}

Camera::~Camera()
{
    //dtor
}

void Camera::setPosition(V3f position){
    m_Position = position;
    turnCamera(0.0, 0.0);
};

void Camera::update(unsigned int ellapsed_time)
{
    /*
    if(m_Up){
        MoveCamera(m_speed * ellapsed_time);
    }
    if(m_Down){
        MoveCamera(-m_speed * ellapsed_time);
    }
    if(m_Left){
        MoveLateralCamera(-m_speed * ellapsed_time);
    }
    if(m_Right){
        MoveLateralCamera(m_speed * ellapsed_time);
    }
 */
    float timeSpeed = (m_speed * ellapsed_time);
    V2f speed;

    if(m_Up){
        speed.x = timeSpeed;
    }
    if(m_Down){
        speed.x = -timeSpeed;
    }
    if(m_Left){
        speed.y = -timeSpeed;
    }
    if(m_Right){
        speed.y = timeSpeed;
    }
    if(!speed.isZero()){
        MoveCamera(speed);
    }
    if(m_Climb){
        UpCamera(timeSpeed);
    }else
    if(m_Crouch){
        UpCamera(-timeSpeed);
    }

    if(m_CaptureMouse){

        V2f rotateAngle = m_mouseStartPos - m_mouseCurrentPos;
        m_mouseStartPos = m_mouseCurrentPos;

        if(!rotateAngle.isZero()){
            // rotateAngle.Normalize();
            // Camera::SetCameraVision(rotateAngle.x, rotateAngle.y);
            Camera::turnCamera(rotateAngle.x, rotateAngle.y);
        }

    }
}


void Camera::handleMessage(Message* message)
{
    switch(message->getEvent())
    {
		case EventType::KEYUP:
			switch(((MessageKeyboard*)message)->GetKey()){
                case SDLK_UP:
                    m_Up = false;
                    break;
                case SDLK_DOWN:
                    m_Down = false;
                    break;
                case SDLK_LEFT:
                    m_Left = false;
                    break;
                case SDLK_RIGHT:
                    m_Right = false;
                    break;
                case SDLK_RCTRL:
                    m_Crouch = false;
                    break;
                case SDLK_RSHIFT:
                    m_Climb = false;
                    break;
			}
			break;

		case EventType::KEYDOWN:
			switch(((MessageKeyboard*)message)->GetKey()){
                case SDLK_UP:
                    m_Up = true;
                    break;
                case SDLK_DOWN:
                    m_Down = true;
                    break;
                case SDLK_LEFT:
                    m_Left = true;
                    break;
                case SDLK_RIGHT:
                    m_Right = true;
                    break;
                case SDLK_RCTRL:
                    m_Crouch = true;
                    break;
                case SDLK_RSHIFT:
                    m_Climb = true;
                    break;
			}
			break;

		case EventType::MOUSEMOTION:
            if(m_CaptureMouse){

                m_mouseCurrentPos.x = ((MessageMouse*)message)->getX();
                m_mouseCurrentPos.y = ((MessageMouse*)message)->getY();
            }
			break;

		case EventType::MOUSEBUTTONDOWN:
		    if(((MessageMouse*)message)->getButton() == 1){

                m_mouseStartPos.x = ((MessageMouse*)message)->getX();
                m_mouseStartPos.y = ((MessageMouse*)message)->getY();
                m_mouseCurrentPos.x = ((MessageMouse*)message)->getX();
                m_mouseCurrentPos.y = ((MessageMouse*)message)->getY();

                m_CaptureMouse = true;
		    }
			break;
		case EventType::MOUSEBUTTONUP:
		    if(((MessageMouse*)message)->getButton() == 1){
                m_CaptureMouse = false;
		    }
			break;
    }
}


void Camera::turnCamera(float xRel, float yRel)
{
    // Récupération des angles

    m_phi += yRel * 0.4;
    m_theta += xRel * 0.4;


    // Limitation de l'angle phi

    if(m_phi > 89.0)
        m_phi = 89.0;

    else if(m_phi < -89.0)
        m_phi = -89.0;


    // Conversion des angles en radian

    float phiRadian = m_phi * M_PI / 180;
    float thetaRadian = m_theta * M_PI / 180;

    V3f m_orientation;

    // Si l'axe vertical est l'axe X

    if(m_UpVector.x == 1.0)
    {
        // Calcul des coordonnées sphériques

        m_orientation.x = sin(phiRadian);
        m_orientation.y = cos(phiRadian) * cos(thetaRadian);
        m_orientation.z = cos(phiRadian) * sin(thetaRadian);
    }


    // Si c'est l'axe Y

    else if(m_UpVector.y == 1.0)
    {
        // Calcul des coordonnées sphériques

        m_orientation.x = cos(phiRadian) * sin(thetaRadian);
        m_orientation.y = sin(phiRadian);
        m_orientation.z = cos(phiRadian) * cos(thetaRadian);
    }


    // Sinon c'est l'axe Z

    else
    {
        // Calcul des coordonnées sphériques

        m_orientation.x = cos(phiRadian) * cos(thetaRadian);
        m_orientation.y = cos(phiRadian) * sin(thetaRadian);
        m_orientation.z = sin(phiRadian);
    }

    // Calcul du point ciblé pour OpenGL

    m_View = m_Position + m_orientation;
}



void Camera::MoveCamera(float speed)
{
	V3f VectorDirection;					// Init a vector for our view

	// Get our view vector (The direciton we are facing)
	VectorDirection = m_View - m_Position;
    VectorDirection = (VectorDirection * speed);

	m_Position = m_Position + VectorDirection;
	m_View = m_View + VectorDirection;

	m_messageBus->sendMessage(new MessagePosition(EventType::CAMERAMOVE, m_Position));

}

void Camera::MoveCamera(V2f speed)
{
	V3f VectorDirection;					// Init a vector for our view

	// Get our view vector (The direciton we are facing)
	VectorDirection = m_View - m_Position;

    if(speed.x != 0.0){
        V3f Direction = (VectorDirection * speed.x);
        m_Position = m_Position + Direction;
        m_View = m_View + Direction;
    }
	if(speed.y != 0.0){
        V3f Strafe = VectorDirection.Cross(m_UpVector);
        Strafe.Normalize();
        Strafe = (Strafe * speed.y);
        m_Position = m_Position + Strafe;
        m_View = m_View + Strafe;
	}

	m_messageBus->sendMessage(new MessagePosition(EventType::CAMERAMOVE, m_Position));

}

void Camera::MoveLateralCamera(float speed)
{
	V3f VectorDirection;// Init a vector for our view

	// Get our view vector (The direciton we are facing)
	VectorDirection = m_View - m_Position;
	V3f Strafe = VectorDirection.Cross(m_UpVector);
    Strafe.Normalize();

    Strafe = (Strafe * speed);

	m_Position = m_Position + Strafe;
	m_View = m_View + Strafe;

	m_messageBus->sendMessage(new MessagePosition(EventType::CAMERAMOVE, m_Position));

}


void Camera::UpCamera(float speed)
{

	m_Position.z +=  speed;
	m_View.z +=  speed;

	m_messageBus->sendMessage(new MessagePosition(EventType::CAMERAMOVE, m_Position));

}



float* Camera::getLookAt()
{
    static float lookAt[9];
    lookAt[0] = m_Position.x;
    lookAt[1] = m_Position.y;
    lookAt[2] = m_Position.z;
    lookAt[3] = m_View.x;
    lookAt[4] = m_View.y;
    lookAt[5] = m_View.z;
    lookAt[6] = m_UpVector.x;
    lookAt[7] = m_UpVector.y;
    lookAt[8] = m_UpVector.z;

    return lookAt;

}

