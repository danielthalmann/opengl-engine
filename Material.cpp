#include "Material.h"

using namespace Cagan;

Material::Material(float red, float green, float blue, std::string name)
{
    m_Color.x = red;
    m_Color.y = green;
    m_Color.z = blue;
    m_Name = name;
}

Material::Material(Material* mat)
{
    m_Name = mat->GetName();
    m_Color = mat->GetColor();
}

Material::~Material()
{

}
