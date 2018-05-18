#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

namespace Cagan
{

    template <class T>
    class Vector3D
    {
        private:



        public:


            T x;
            T y;
            T z;

            // fonction du constructeur
            Vector3D(T X, T Y, T Z){ x = X; y = Y; z = Z; }

            // fonction du constructeur
            Vector3D(){ x = 0; y = 0; z = 0; }

            // transform tous les vecteurs en positif
            void setToPositiveSign()
            {
                if(x < 0) x = -x;
                if(y < 0) y = -y;
                if(z < 0) x = -z;
            }

            T* getTable()
            {
                T m_tbl[3];

                m_tbl[0] = x;
                m_tbl[1] = y;
                m_tbl[2] = z;
                return m_tbl;
            }


            // Retourne un vecteur à partir du point (0,0,0) d'une valeur de 1
            // exemple, avec le vecteur (2,0,0) on obtiendra (1,0,0)
            void Normalize()
            {
                T magnitude = (T)sqrt( (x * x) + (y * y) + (z * z) );
                x /=  magnitude;
                y /=  magnitude;
                z /=  magnitude;
            }

            Vector3D<T> Cross(Vector3D<T> Vector)
            {

                Vector3D<T> newVector;                              // The vector to hold the cross product

                // If we are given 2 vectors (the view and up vector) then we have a plane define.
                // The cross product finds a vector that is perpendicular to that plane,
                // which means it's point straight out of the plane at a 90 degree angle.
                // The equation for the cross product is simple, but difficult at first to memorize:

                // The X value for the vector is:  (V1.y * V2.z) - (V1.z * V2.y)                                                    // Get the X value
                newVector.x = ((y * Vector.z) - (z * Vector.y));

                // The Y value for the vector is:  (V1.z * V2.x) - (V1.x * V2.z)
                newVector.y = ((z * Vector.x) - (x * Vector.z));

                // The Z value for the vector is:  (V1.x * V2.y) - (V1.y * V2.x)
                newVector.z = ((x * Vector.y) - (y * Vector.x));

                // *IMPORTANT* This is not communitive. You can not change the order or this or
                // else it won't work correctly.  It has to be exactly like that.  Just remember,
                // If you are trying to find the X, you don't use the X value of the 2 vectors, and
                // it's the same for the Y and Z.  You notice you use the other 2, but never that axis.
                // If you look at the camera rotation tutorial, you will notice it's the same for rotations.

                // So why do I need the cross product to do a first person view?  Well, we need
                // to find the axis that our view has to rotate around.  Rotating the camera left
                // and right is simple, the axis is always (0, 1, 0).  Rotating around the camera
                // up and down is different because we are constantly going in and out of axises.
                // We need to find the axis that our camera is on, and that is why we use the cross
                // product.  By taking the cross product between our view vector and up vector,
                // we get a perpendicular vector to those 2 vectors, which is our desired axis.
                // Pick up a linear algebra book if you don't already have one, you'll need it.

                // Return the cross product
                return newVector;
            }

            // surcharge l'operateur +
            Vector3D<T> operator+(Vector3D<T> aVector)
            {
                // Return the added vectors result.
                return Vector3D<T>(x + aVector.x, y + aVector.y, z + aVector.z);
            }

            // surcharge l'operateur -
            Vector3D<T> operator-(Vector3D<T> aVector)
            {
                // Return the added vectors result.
                return Vector3D<T>(x - aVector.x, y - aVector.y, z - aVector.z);
            }

            // surcharge l'operateur *
            Vector3D<T> operator*(Vector3D<T> aVector)
            {
                // Return the added vectors result.
                return Vector3D<T>(x * aVector.x, y * aVector.y, z * aVector.z);
            }

            // surcharge l'operateur *
            Vector3D<T> operator*(T num)
            {
                // Return the added vectors result.
                return Vector3D<T>(x * num, y * num, z * num);
            }

            // surcharge l'operateur /
            Vector3D<T> operator/(Vector3D<T> aVector)
            {
                // Return the added vectors result.
                return Vector3D<T>(x / aVector.x, y / aVector.y, z / aVector.z);
            }

            // surcharge l'operateur /
            Vector3D<T> operator/(T num)
            {
                // Return the added vectors result.
                return Vector3D<T>(x / num, y / num, z / num);
            }

    };


    template <class T>
    class Vector2D
    {
        public:

            T x;
            T y;

            // Vector2D(Vector2D<T> aVector){ x = aVector.x; y = aVector.y; }

            Vector2D(T X, T Y){ x = X; y = Y; }

            Vector2D(){ x = 0; y = 0; }

            bool isZero(){
                if(x == (T)0.0 && y == (T)0.0){
                    return true;
                }else {
                    return false;
                }
            }

            // surcharge l'operateur -
            Vector2D<T> operator-(Vector2D<T> aVector)
            {
                // Return the added vectors result.
                return Vector2D<T>(x - aVector.x, y - aVector.y);
            }

            Vector2D<T> operator=(Vector2D<T> aVector)
            {
                // Return the added vectors result.
                x = aVector.x;
                y = aVector.y;
                return Vector2D<T>(aVector.x, aVector.y);
            }

            void Normalize()
            {
                T magnitude = (T)sqrt( (x * x) + (y * y)  );
                x /=  magnitude;
                y /=  magnitude;
            }

    };

    typedef Vector3D<float> V3f;

    typedef Vector2D<float> V2f;
    typedef Vector2D<int> V2i;


}


#endif // VECTOR_H
