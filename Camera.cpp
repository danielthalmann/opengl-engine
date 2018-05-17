#include "Camera.h"

using namespace Cagan;

Camera::Camera(MessageBus* messageBus) : IMessageReceiver(messageBus)
{
	m_Position = V3f(3.0, 4.0, 2.0);
	m_View =     V3f(0.0, 0.0, 0.0);
	m_UpVector = V3f(0.0, 0.0, 1.0);
}

Camera::~Camera()
{
    //dtor
}

void Camera::handleMessage(Message* message)
{
    switch(message->getEvent())
    {
		case EventType::MOUSEMOTION:
			// std::cout << "MOUSEMOTION X:" << ((MessageMouse*)message)->getX() << " y:" << ((MessageMouse*)message)->getY();
			break;
		case EventType::KEYDOWN:
			MoveCamera(0.02);
			break;

    }
}

void Camera::RotateView(float angle, float x, float y, float z)
{
	V3f NewView;

	// Get the view vector (The direction we are facing)
	V3f View = m_View - m_Position;

	// Calcul le sinus et le cosinus de l'angle
	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);

	// Find the new x position for the new rotated point
	NewView.x  = (cosTheta + (1 - cosTheta) * x * x)		* View.x;
	NewView.x += ((1 - cosTheta) * x * y - z * sinTheta)	* View.y;
	NewView.x += ((1 - cosTheta) * x * z + y * sinTheta)	* View.z;

	// Find the new y position for the new rotated point
	NewView.y  = ((1 - cosTheta) * x * y + z * sinTheta)	* View.x;
	NewView.y += (cosTheta + (1 - cosTheta) * y * y)		* View.y;
	NewView.y += ((1 - cosTheta) * y * z - x * sinTheta)	* View.z;

	// Find the new z position for the new rotated point
	NewView.z  = ((1 - cosTheta) * x * z - y * sinTheta)	* View.x;
	NewView.z += ((1 - cosTheta) * y * z + x * sinTheta)	* View.y;
	NewView.z += (cosTheta + (1 - cosTheta) * z * z)		* View.z;

	// Now we just add the newly rotated vector to our position to set
	// our new rotated view of our camera.
	m_View = m_Position + NewView;
}


void Camera::MoveCamera(float speed)
{
	V3f VectorDirection;					// Init a vector for our view

	// Get our view vector (The direciton we are facing)
	VectorDirection = m_View - m_Position;

	m_Position.x += VectorDirection.x * speed;
	m_Position.z += VectorDirection.z * speed;
	m_View.x += VectorDirection.x * speed;
	m_View.z += VectorDirection.z * speed;

}

void Camera::StrafeCamera(float speed)
{
	// Strafing is quite simple if you understand what the cross product is.
	// If you have 2 vectors (say the up vVector and the view vVector) you can
	// use the cross product formula to get a vVector that is 90 degrees from the 2 vectors.
	// For a better explanation on how this works, check out the OpenGL "Normals" tutorial at our site.
	// In our new Update() function, we set the strafing vector (m_vStrafe).  Due
	// to the fact that we need this vector for many things including the strafing
	// movement and camera rotation (up and down), we just calculate it once.
	//
	// Like our MoveCamera() function, we add the strafing vector to our current position
	// and view.  It's as simple as that.  It has already been calculated in Update().

	// Initialize a variable for the cross product result

	V3f VectorDirection = m_View - m_Position;

	V3f m_Strafe = VectorDirection.Cross(m_UpVector);

	// Normalize the strafe vector
	m_Strafe.Normalize();

	// Add the strafe vector to our position
	m_Position.x += m_Strafe.x * speed;
	m_Position.z += m_Strafe.z * speed;

	// Add the strafe vector to our view
	m_View.x += m_Strafe.x * speed;
	m_View.z += m_Strafe.z * speed;

}

void Camera::UpCamera(float speed)
{
	// Strafing is quite simple if you understand what the cross product is.
	// If you have 2 vectors (say the up vVector and the view vVector) you can
	// use the cross product formula to get a vVector that is 90 degrees from the 2 vectors.
	// For a better explanation on how this works, check out the OpenGL "Normals" tutorial at our site.
	// In our new Update() function, we set the strafing vector (m_vStrafe).  Due
	// to the fact that we need this vector for many things including the strafing
	// movement and camera rotation (up and down), we just calculate it once.
	//
	// Like our MoveCamera() function, we add the strafing vector to our current position
	// and view.  It's as simple as that.  It has already been calculated in Update().

	// Initialize a variable for the cross product result

	// Add the strafe vector to our position
	m_Position.y +=  speed;
	m_View.y +=  speed;

}


void Camera::SetCameraVision(float angleY, float angleZ)
{
    static float currentRotX = 0.0f;

	// Here we keep track of the current rotation (for up and down) so that
    // we can restrict the camera from doing a full 360 loop.
    currentRotX -= angleZ;

    if(currentRotX > 1.0f)
        currentRotX = 1.0f;

	else if(currentRotX < -1.0f)
        currentRotX = -1.0f;
	else
	{
		V3f ViewVector = m_View - m_Position;

		V3f vAxis = ViewVector.Cross(m_UpVector);
		vAxis.Normalize();

		RotateView(angleZ, vAxis.x, vAxis.y, vAxis.z);
	}

    RotateView(angleY, 0, 1, 0);


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
