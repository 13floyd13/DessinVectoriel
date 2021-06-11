#include "cercle.h"

#include <cstdlib>

#define _USE_MATH_DEFINES   // To include PI value
#include <math.h>



Cercle::Cercle(Point centre, int radius, std::string label, std::string color, std::string fillColor, int thickness) :
        Forme(label,color,fillColor, thickness),
        m_center(centre),
        m_radius(radius){}


/*Cercle::Cercle()
{
}*/

// constructeur de copie
Cercle::Cercle(const Cercle &other) : Forme(*other.m_label,*other.m_color,*other.m_fillColor, other.m_thickness), m_center(other.m_center), m_radius(other.m_radius)
{}

Cercle::~Cercle()
{}

Cercle &Cercle::operator=(const Cercle &other)
{
    if (this == &other) return *this;

    *m_label = *other.m_label;
    *m_color = *other.m_color;
    *m_fillColor=*other.m_fillColor;
    m_thickness = other.m_thickness;
    m_center = other.m_center;
    m_radius = other.m_radius;
    return *this;
}


float Cercle::Surface() const
{
    return m_radius * m_radius * (float)M_PI;
}

float Cercle::Perimeter() const
{
    return m_radius * (float)M_PI * 2.f;
}


/*void Cercle::Display(MyDrawingPanel drawingPanel) const
{
    drawingPanel.OnDrawCercle(this);
}*/
const Point& Cercle::GetCentre(){
    return m_center;
}
const int Cercle::GetRadius(){
    return m_radius;
}
