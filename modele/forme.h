#ifndef __FORME_H__
#define __FORME_H__

#include <string>



class Forme
{
public:
    // Construction/Destruction
    Forme();
    Forme(const std::string& label, int color,int fillColor, int thickness);    // Avec une string
    Forme(const Forme& other);          // Construction par recopie
    virtual ~Forme();

    // Operator d'affectation
    Forme& operator=(const Forme& other);


    void SetLabel(const std::string& s);
    void SetColor(int color);
    void SetFillColor(int fillColor);
    void SetThickness(int thickness);
    std::string GetLabel() const;
    int GetColor() const;
    int GetFillColor() const;
    int GetThickness() const;


   /*virtual void Display() const
    {

    }*/

    virtual float Surface() const { return 0.0f; }
    virtual float Perimeter() const { return 0.0f; }

protected:
    std::string * m_label;
    int m_color;
    int m_fillColor;
    int m_thickness;
};

#endif
