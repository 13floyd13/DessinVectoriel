
#include "forme.h"

using namespace std;

Forme::Forme()
{
    m_label = new string;
    m_color = new string;
}

Forme::Forme(const std::string& label, const std::string& color, const std::string& fillColor, int thickness)
{
    m_label = new string(label);
    m_color = new string(color);
    m_fillColor= new string(fillColor);
    m_thickness = thickness;
}

Forme::Forme(const Forme& other)
{
    m_color = new string(*(other.m_color));
    m_fillColor= new string(*(other.m_fillColor));
    m_label = new string(*(other.m_label));
    m_thickness = other.m_thickness;
}

// virtual
Forme::~Forme()
{
    delete m_label;
    delete m_color;
    delete m_fillColor;
}

Forme& Forme::operator=(const Forme& other)
{
    SetLabel(*(other.m_label));
    SetColor(*(other.m_color));
    SetFillColor(*(other.m_color));
    SetThickness(other.m_thickness);
    return *this;
}

void Forme::SetLabel(const std::string& label)
{
    *m_label = label;
}
void Forme::SetColor(const std::string &color) {

    *m_color= color;
}
void Forme::SetFillColor(const std::string &fillColor) {
    *m_fillColor= fillColor;
}

void Forme::SetThickness(int thickness) {
    m_thickness = thickness;
}

std::string Forme::GetLabel() const
{

    return *(m_label);
}
std::string Forme::GetColor() const {

    return *(m_color);
}
std::string Forme::GetFillColor() const {

    return *(m_fillColor);
}

int Forme::GetThickness() const {
    return m_thickness;
}