#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"
#include "MessageBus.h"
#include "Object.h"

namespace Cagan
{
    class Camera : public IMessageReceiver, public Object
    {
        public:
            Camera(MessageBus* messageBus);
            virtual ~Camera();

            void handleMessage(Message* message);

            void RotateView(float angle, float x, float y, float z);
            void MoveCamera(float speed);
            void MoveCamera(V2f speed);
            void UpCamera(float speed);
            void SetCameraVision(float angleY, float angleZ);
            float* getLookAt();
            void update(unsigned int ellapsed_time);
            void orienter(float xRel, float yRel);
            void MoveLateralCamera(float speed);


        protected:

            V3f m_View;
            V3f m_UpVector;

            bool m_Up;
            bool m_Down;
            bool m_Left;
            bool m_Right;
            bool m_Climb;
            bool m_Crouch;

            bool m_CaptureMouse;

            float m_speed;

            V2f m_mouseStartPos;
            V2f m_mouseCurrentPos;

            float m_phi;
            float m_theta;

        private:
    };

}

#endif // CAMERA_H
