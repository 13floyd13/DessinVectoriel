
#include "forme.h"

using namespace std;

Forme::Forme()
{
    m_label = new string;
}

Forme::Forme(const std::string& label)
{
    m_label = new string(label);
}

Forme::Forme(const Forme& other)
{

    m_label = new string(*(other.m_label));
}

// virtual
Forme::~Forme()
{
    delete m_label;
}

Forme& Forme::operator=(const Forme& other)
{
    SetLabel(*(other.m_label));
    return *(this);
}

void Forme::SetLabel(const std::string& label)
{
    *m_label = label;
}

std::string Forme::GetLabel() const
{

    return *(m_label);
}