#include "cercle.h"

#include <cstdlib>

#define _USE_MATH_DEFINES   // To include PI value
#include <math.h>
#include <fstream>
#include <iostream>


Cercle::Cercle(Point centre, int radius, std::string label, int color, int fillColor, int thickness) :
        Forme(label,color,fillColor, thickness),
        m_center(centre),
        m_radius(radius){}



// constructeur de copie
Cercle::Cercle(const Cercle &other) : Forme(*other.m_label,other.m_color,other.m_fillColor, other.m_thickness), m_center(other.m_center), m_radius(other.m_radius)
{}

Cercle::~Cercle()
{}


bool Cercle::IsInside(int x, int y) const {
    int xCentre= this->GetCentre().GetX();
    int yCentre= this->GetCentre().GetY();

    int distance= sqrt(x-xCentre)*(x-xCentre)+(y-yCentre)*(y-yCentre);
    if(distance < this->GetRadius()){
        return true;
    } else{
        return false;
    }
}
const Point & Cercle::GetCentre() const {
    return m_center;
}
const int Cercle::GetRadius() const{
    return m_radius;
}
/*void Cercle::Save(std::ostream f) {
    /*try
    {

        //std::ofstream fichier_sortant (chemin.c_str(), std::ios::binary);

       // f.write ((char*) this, sizeof (*this));
        super::Save(f,1);

        m_center.Save(f);
        f.write((const char*)&m_radius, sizeof(m_radius));
    /*}
   /* catch (const char *exception)
    {
        std::cerr << "\n*** " << exception << " ***\n";
    }
    catch (...)
    {
        std::cerr << "\n*** Une erreur s'est produite ! ***\n";
    }
}

void Cercle::Load()
{

}*/
