

#include "point.h"

#include <iostream>
#include <cstdlib>
#include <cmath> // pour sqrt

//-------------------------------------------
Point::Point()
//-------------------------------------------
{
    m_x = m_y = 0;

}

//-------------------------------------------
Point::Point(int x, int y)
//-------------------------------------------
{
            m_x = x;
    m_y = y;

}

//-------------------------------------------
Point::Point(int z)
//-------------------------------------------
{
    m_x = m_y = z;

}

//-------------------------------------------
Point::~Point()
//-------------------------------------------
{

}

//-------------------------------------------
void Point::Move(int dX, int dY)
//-------------------------------------------
{
    m_x += dX;
    m_y += dY;
}

//-------------------------------------------
/*void Point::Display() const
//-------------------------------------------
{

}*/

//-------------------------------------------

//-------------------------------------------
int Point::GetX() const
//-------------------------------------------
{
    return m_x;
}

//-------------------------------------------
int Point::GetY() const
//-------------------------------------------
{
    return m_y;
}

//-------------------------------------------
void Point::SetX(int x)
//-------------------------------------------
{
    m_x = x;
}

//-------------------------------------------
void Point::SetY(int y)
//-------------------------------------------
{
    m_y = y;
}

//-------------------------------------------


//-------------------------------------------
float Point::Distance(const Point *p) const
//-------------------------------------------

{
    return sqrt((m_x - p->m_x) * (m_x - p->m_x) + (m_y - p->m_y) * (m_y - p->m_y));
}

//-------------------------------------------
float Point::Distance(const Point &p) const

//-------------------------------------------
{
    return sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}
void Point::Save(std::ostream f) {
    f.write((const char*)&m_x, sizeof(m_x));
    f.write((const char*)&m_y, sizeof(m_y));
}
Point Point::Load(std::istream f){
    int x;
    int y;
    f.read((char*)x, sizeof(x));
    f.read((char*)y, sizeof(y));
    return Point(x,y);
}


