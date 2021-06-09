#include "cercle.h"

#include <cstdlib>

#define _USE_MATH_DEFINES   // To include PI value
#include <math.h>



Cercle::Cercle(Point centre, int radius, std::string label) :
        Forme(label),
        m_center(centre),
        m_radius(radius){}


/*Cercle::Cercle()
{
}*/

// constructeur de copie
Cercle::Cercle(const Cercle &other) : Forme(*other.m_label), m_center(other.m_center), m_radius(other.m_radius)
{}

Cercle::~Cercle()
{}

Cercle &Cercle::operator=(const Cercle &other)
{
    if (this == &other) return *this;

    *m_label = *other.m_label;
    m_center = other.m_center;
    m_radius = other.m_radius;
    return *this;
}


/*float Cercle::Surface() const
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