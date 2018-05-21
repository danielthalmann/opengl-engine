#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "vector.h"

// https://openclassrooms.com/courses/charger-des-fichiers-obj
namespace Cagan
{
    class Material
    {
        public:
            Material(float red, float green, float blue, std::string name);
            Material(Material *mat);
            virtual ~Material();

            V4f GetColor() { return m_Color; }
            void SetColor(V4f val) { m_Color = val; }

            std::string GetName() { return m_Name; }



        protected:
            V4f m_Color;
            std::string m_Name;

        private:
    };
}

#endif // MATERIAL_H
