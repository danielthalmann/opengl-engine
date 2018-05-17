#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"
#include "MessageBus.h"

namespace Cagan
{
    class Camera : public IMessageReceiver
    {
        public:
            Camera(MessageBus* messageBus);
            virtual ~Camera();

            void handleMessage(Message* message);

            void RotateView(float angle, float x, float y, float z);
            void MoveCamera(float speed);
            void StrafeCamera(float speed);
            void UpCamera(float speed);
            void SetCameraVision(float angleY, float angleZ);
            float* getLookAt();



        protected:

            V3f m_Position;
            V3f m_View;
            V3f m_UpVector;

        private:
    };

}

#endif // CAMERA_H
