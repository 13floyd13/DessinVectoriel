#include <cmath>
#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h, const std::string& label, const std::string& color, const std::string& fillColor, int thickness) :
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
Rectangle::Rectangle(const Point& p, int w, int h, const std::string& label, const std::string& color, const std::string& fillColor, int thickness) :
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
/*void Rectangle::Display(MyDrawPanel drawPanel) const
//-------------------------------------------
{
    drawingPanel.OnDrawRect(this);
}*/

//-------------------------------------------
/*void Rectangle::Move(int dX, int dY)
//-------------------------------------------
{

    m_corner.Move(dX, dY);
}

//-------------------------------------------


//-------------------------------------------
bool Rectangle::IsInside(const Rectangle &r) const
//-------------------------------------------
// retourne true si le rectangle est enti�rement � l'int�rieur (inclus) dans le Rectangle r
// si r1 est inclus dans r2
{
    // On r�cup�re les valeurs des points du rectangle
    int x1r1 = GetCorner().GetX();
    int y1r1 = GetCorner().GetY();
    int x2r1 = x1r1 + m_w;
    int y2r1 = y1r1 + m_h;
    int x1r2 = r.GetCorner().GetX();
    int y1r2 = r.GetCorner().GetY();
    int x2r2 = x1r2 + r.GetWidth();
    int y2r2 = y1r2 + r.GetHeight();

    // On v�rifier que r est inclus dans ce Rectangle (this)
    return ((x1r1 > x1r2 && x1r1 < x2r2) || (x1r1 < x1r2 && x1r1 > x2r2)) &&
           ((x1r1 > x1r2 && x1r1 < x2r2) || (x1r1 < x1r2 && x1r1 > x2r2));
}*/

bool Rectangle::IsInside(int x,int y) const {
   int rectX= this->GetCorner().GetX();
   int rectY= this->GetCorner().GetY();
   int rectXoppose= rectX+ this->GetWidth();
   int rectYoppose= rectY+ this->GetHeight();
   int xMin=0;
   int xMax=0;
   int yMin=0;
   int yMax=0;

   if(rectX > rectXoppose){
       xMin=rectXoppose;
       xMax=rectX;
   }else{
       xMin=rectX;
       xMax=rectXoppose;
   }

   if(rectY > rectYoppose){
       yMin=rectYoppose;
       yMax=rectY;
   }else{
       yMin=rectY;
       yMax=rectYoppose;
   }

   if(x<xMin || x>xMax || y<yMin || y>yMax){
       return false;
   }else{
       return true;
   }

float Rectangle::Surface() const
{
    return (float)(m_w * m_h);
}

float Rectangle::Perimeter() const
{
    return (float)(2*m_w + 2*m_h);;
}
