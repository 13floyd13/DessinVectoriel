#include <cmath>
#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h, const std::string& label, int color, int fillColor, int thickness) :
// Appel du constructeur de Forme avec un label

        Forme(label,color,fillColor,thickness)
//-------------------------------------------
// attention, cette version appelle le constructeur par d�faut de Point
// comme le compilateur ne l?a pas cr��, il faut le rajouter dans Point
{

    m_corner.SetX(x);
    m_corner.SetY(y);
    m_w = w;
    m_h = h;

}

//-------------------------------------------
Rectangle::Rectangle(const Point& p, int w, int h, const std::string& label, int color, int fillColor, int thickness) :
        Forme(label,color,fillColor, thickness),
        m_corner(p.GetX(),p.GetY()),
        m_w(w),
        m_h(h){}

//-------------------------------------------
Rectangle::~Rectangle(){}

//-------------------------------------------
void Rectangle::SetCorner(const Point& p)
//-------------------------------------------
{

    m_corner = p;
}

//-------------------------------------------
void Rectangle::SetWidth(int w)
//-------------------------------------------
{
    m_w = w;
}

//-------------------------------------------
void Rectangle::SetHeight(int h)
//-------------------------------------------
{
    m_h = h;
}

//-------------------------------------------
const Point& Rectangle::GetCorner() const
//-------------------------------------------
{

    return m_corner;
}

//-------------------------------------------
int Rectangle::GetWidth() const
//-------------------------------------------
{
    return m_w;
}

//-------------------------------------------
int Rectangle::GetHeight() const
//-------------------------------------------
{
    return m_h;
}

//-------------------------------------------


bool Rectangle::IsInside(int x,int y) const {
    int rectX = this->GetCorner().GetX();
    int rectY = this->GetCorner().GetY();
    int rectXoppose = rectX + this->GetWidth();
    int rectYoppose = rectY + this->GetHeight();
    int xMin = 0;
    int xMax = 0;
    int yMin = 0;
    int yMax = 0;

    if (rectX > rectXoppose) {
        xMin = rectXoppose;
        xMax = rectX;
    } else {
        xMin = rectX;
        xMax = rectXoppose;
    }

    if (rectY > rectYoppose) {
        yMin = rectYoppose;
        yMax = rectY;
    } else {
        yMin = rectY;
        yMax = rectYoppose;
    }

    return !(x < xMin || x > xMax || y < yMin || y > yMax);
}


