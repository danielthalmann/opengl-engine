#ifndef MESH_H
#define MESH_H

#include <GL/gl.h>
#include <GL/glu.h>

#include <string>
#include <vector>
#include <fstream>

#include "Object.h"
#include "Material.h"

namespace Cagan
{
    class Mesh : public Object
    {
        public:
            Mesh(std::string filename, Mesh *first = NULL);
            virtual ~Mesh();

            void LoadObject(std::string filename, Mesh *first=NULL);

            /* void charger_obj(std::string,Mesh *first=NULL);

               Charge un fichier OBJ et son MTL, prend en arguments le nom du modèle à charger et le pointeur de la première frame si le modèle appartient à une animation (sinon laissez-le à NULL). Cette fonction est appelée par le constructeur.

               Aucune valeur de retour.

            */

            void LoadMaterial(std::string filename);

            /* void charger_mtl(std::string);

               Charge un fichier MTL, prend en argument le nom du fichier à charger. Cette fonction est appelée par charger_obj.

               Aucune valeur de retour.

            */

            virtual void draw();

            /* virtual void draw();

               Dessine le modèle,

               Aucune valeur de retour.

            */

            void setMaterialsAndTex(std::vector<Material*> mats, unsigned int tex);

            /* void setMaterialsAndTex(std::vector<Material*> mats,GLuint tex);

               Définit directement les matériaux et la texture du modèle, prend en arguments un vector<Material*> et la texture. Cette fonction est appelée par giveMaterialsAndTex.

               Aucune valeur de retour.

            */

            void giveMaterialsAndTex(Mesh *target);

            /* void giveMaterialsAndTex(Mesh *target);

               Modifie les matériaux et la texture de target en les remplaçant par ses propres matériaux et sa texture. Cette fonction est appelée par charger_obj uniquement lorsque first!=NULL.

               Aucune valeur de retour.

            */

        private:

            unsigned int texture;

            int n_data;

            float *vertice,*normals,*textures,*colours;

            std::vector<Material*> m_Materials;


            std::string doubleSlash(std::string s);
            std::string remplacerSlash(std::string s);
            std::vector<std::string> splitSpace(std::string s);
            std::string get_directory(std::string s);
            float* vector2float(std::vector<float>& tableau);

            protected:

        private:
    };
}

#endif // MESH_H
