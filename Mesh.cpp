#include "Mesh.h"

using namespace Cagan;


Mesh::Mesh(std::string filename, Mesh* first)
{
    LoadObject(filename, first);
}

Mesh::~Mesh()
{
    free(vertice);
    free(normals);
    free(textures);
    free(colours);

    for(unsigned int i=0; i<m_Materials.size(); i++)
        delete m_Materials[i];

    m_Materials.clear();
}

void Mesh::LoadObject(std::string filename, Mesh* first)
{

    std::vector<V4f> col;
    std::vector<V3f> ver,nor;
    std::vector<V2f> tex;
    std::vector<unsigned int> iv,it,in;

    std::ifstream fichier;

    std::string ligne, curname="";

    fichier.open(filename.c_str(), std::ios::in);

    while(fichier.good()){

        std::getline(fichier, ligne);

        if(ligne[0]=='v') //Coordonnées de points (vertex, texture et normale)
        {
            if(ligne[1]==' ') //Vertex
            {
                char x[255],y[255],z[255];
                sscanf(ligne.c_str(),"v %s %s %s",x,y,z);
                ver.push_back(V3f(strtof(x,NULL),strtof(y,NULL),strtof(z,NULL)));
            }

            else if(ligne[1]=='t') //Texture
            {
                char x[255],y[255];
                sscanf(ligne.c_str(),"vt %s %s",x,y);
                tex.push_back(V2f(strtof(x,NULL),strtof(y,NULL)));
            }

            else if(ligne[1]=='n') //Normale
            {
                char x[255],y[255],z[255];
                sscanf(ligne.c_str(),"vn %s %s %s",x,y,z);
                nor.push_back(V3f(strtof(x,NULL),strtof(y,NULL),strtof(z,NULL)));
            }
        }
        else if(ligne[0]=='f') //Indice faces
        {
            ligne=doubleSlash(ligne); //On remplace "//" par "/1/" dans toute la ligne
            ligne=remplacerSlash(ligne); //On remplace les '/' par des espaces, ex : pour "f 1/2/3 4/5/6 7/8/9" on obtiendra "f 1 2 3 4 5 6 7 8 9"

            std::vector<std::string> termes=splitSpace(ligne.substr(2)); //On éclate la chaîne en ses espaces (le substr permet d'enlever "f ")

            int ndonnees=(int)termes.size()/3;
            for(int i=0;i<(ndonnees==3?3:4);i++) //On aurait très bien pu mettre i<ndonnees mais je veux vraiment limiter à 3 ou 4
            {

                iv.push_back(strtol(termes[i*3].c_str(),NULL,10)-1);
                it.push_back(strtol(termes[i*3+1].c_str(),NULL,10)-1);
                in.push_back(strtol(termes[i*3+2].c_str(),NULL,10)-1);

            }
            if(ndonnees==3) //S'il n'y a que 3 sommets on duplique le dernier pour faire un quad ayant l'apparence d'un triangle
            {
                iv.push_back(strtol(termes[0].c_str(),NULL,10)-1);
                it.push_back(strtol(termes[1].c_str(),NULL,10)-1);
                in.push_back(strtol(termes[2].c_str(),NULL,10)-1);
            }

            for(unsigned int i=0;i<m_Materials.size();i++){

                if(m_Materials[i]->GetName()==curname)
                {
                    for(int j=0;j<4;j++){
                        col.push_back(m_Materials[i]->GetColor()); //On ajoute la couleur correspondante
                    }
                    break;

                }
            }
        }
        else if(ligne[0]=='m' && first==NULL) {//fichier MTL et si c'est la première frame (comme ça on ne charge pas plusieurs fois le même MTL et la même texture)

            LoadMaterial(get_directory(filename)+ligne.substr(7));

        }
        else if(ligne[0]=='u'){ //utiliser un MTL

            curname=ligne.substr(7);

        }

    }

    fichier.close();


    // Le parsage est terminé, après avoir fermé le fichier on applique les indices de sommets pour avoir toutes les faces :

    std::vector<float> tv(0),tc(0),tn(0),tt(0);

    for(unsigned int i=0;i<iv.size();i++)
        if(iv[i]<ver.size())
        {
            tv.push_back(ver[iv[i]].x);
            tv.push_back(ver[iv[i]].y);
            tv.push_back(ver[iv[i]].z);

            tc.push_back(col[i].x);
            tc.push_back(col[i].y);
            tc.push_back(col[i].z);
            tc.push_back(col[i].a);
        }

    for(unsigned int i=0;i<in.size();i++)
        if(in[i]<nor.size())
        {
            tn.push_back(nor[in[i]].x);
            tn.push_back(nor[in[i]].y);
            tn.push_back(nor[in[i]].z);
        }

    for(unsigned int i=0;i<it.size();i++)
        if(it[i]<tex.size())
        {
            tt.push_back(tex[it[i]].x);
            tt.push_back(tex[it[i]].y);
        }

    vertice=vector2float(tv);
    normals=vector2float(tn);
    textures=vector2float(tt);
    colours=vector2float(tc);

    n_data=iv.size();

    ver.clear();
    nor.clear();
    tex.clear();
    col.clear();

    iv.clear();
    it.clear();
    in.clear();


}

float* Mesh::vector2float(std::vector<float>& tableau)
{
    float* t=NULL;
    t=(float*)malloc(tableau.size()*sizeof(float));
    if(t==NULL||tableau.empty())
    {
        float *t1=(float*)malloc(sizeof(float)*3);
        for(int i=0;i<3;i++)
            t1[i]=0.;
        return t1;
    }

    for(unsigned int i=0;i<tableau.size();i++)
        t[i]=tableau[i];
    return t;
}



void Mesh::LoadMaterial(std::string filename)
{
    std::ifstream fichier;
    std::string ligne, curname="";

    fichier.open(filename.c_str(), std::ios::in);

    while(fichier.good()){

        std::getline(fichier, ligne);

        if(ligne[0]=='n') {//nouveau materiau
            curname = ligne.substr(7);
        }
        else if(ligne[0]=='K' && ligne[1]=='d') //couleur
        {
            std::vector<std::string> termes = splitSpace(ligne.substr(3));
            m_Materials.push_back(new Material((float)strtod(termes[0].c_str(),NULL),(float)strtod(termes[1].c_str(),NULL),(float)strtod(termes[2].c_str(),NULL),curname));
        }
        else if(ligne[0]=='m'&&ligne[5]=='d')//map_Kd (texture)
        {
            std::string f=get_directory(filename)+ligne.substr(7);
            m_Texture=loadTexture(f.c_str());
        }
        else if(ligne[0]=='d') //opacité
        {
            std::string n = ligne.substr(2);
            V4f color = m_Materials[m_Materials.size()-1]->GetColor();
            color.a = strtof(n.c_str(),NULL);
            m_Materials[m_Materials.size()-1]->SetColor(color);

        }

    }

    fichier.close();

}

std::string Mesh::doubleSlash(std::string s)
{
    //Remplace "//" par "/1/".
    std::string s1="";
    for(unsigned int i=0;i<s.size();i++)
    {
        if(i<s.size()-1&&s[i]=='/'&&s[i+1]=='/')
        {
            s1+="/1/";
            i++;
        }
        else
            s1+=s[i];
    }
    return s1;
}

std::string Mesh::remplacerSlash(std::string s)
{
    //Remplace les '/' par des espaces.
    std::string ret="";
    for(unsigned int i=0;i<s.size();i++)
    {
        if(s[i]=='/')
            ret+=' ';
        else
            ret+=s[i];
    }
    return ret;
}

std::vector<std::string> Mesh::splitSpace(std::string s)
{
    //Eclate une chaîne au niveau de ses espaces.
    std::vector<std::string> ret;
    std::string s1="";
    for(unsigned int i=0;i<s.size();i++)
    {
        if(s[i]==' '||i==s.size()-1)
        {
            if(i==s.size()-1)
                s1+=s[i];
            ret.push_back(s1);
            s1="";
        }
        else
            s1+=s[i];

    }
    return ret;

}

std::string Mesh::get_directory(std::string s)
{
    std::string s1="",s2="";
    for(unsigned int i=0;i<s.size();i++)
    {
        if(s[i]=='/'||s[i]=='\\')
        {
            s1+=s2+"/";
            s2="";
        }
        else
            s2+=s[i];
    }
    return s1;
}

void Mesh::setMaterialsAndTex(std::vector<Material*>mats, unsigned int tex)
{

}

void Mesh::giveMaterialsAndTex(Mesh* target)
{

}

void Mesh::draw()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    // Si on veut tenir compte des normales on les actives
    // glEnableClientState(GL_NORMAL_ARRAY);

    // Les textures
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    if(m_Texture != NULL)
        glBindTexture(GL_TEXTURE_2D, m_Texture);

    // glEnableClientState(GL_COLOR_ARRAY);


    glVertexPointer(3,GL_FLOAT,0,vertice);

    glTexCoordPointer(2,GL_FLOAT,0,textures);

    glNormalPointer(GL_FLOAT,0,normals);

    // glColorPointer(4,GL_FLOAT,0,colours);

    glDrawArrays(GL_QUADS,0,n_data);



    glDisableClientState(GL_COLOR_ARRAY);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glDisableClientState(GL_NORMAL_ARRAY);

    glDisableClientState(GL_VERTEX_ARRAY);


}
