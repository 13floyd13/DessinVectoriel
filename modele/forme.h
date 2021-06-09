#ifndef __FORME_H__
#define __FORME_H__

#include <string>



class Forme
{
public:
    // Construction/Destruction
    Forme();
    Forme(const std::string& label);    // Avec une string
    Forme(const Forme& other);          // Construction par recopie
    virtual ~Forme();

    // Operator d'affectation
    Forme& operator=(const Forme& other);


    void SetLabel(const std::string& s);
    std::string GetLabel() const;


   /*virtual void Display() const
    {

    }*/

    /*virtual float Surface() const { return 0.0f; }
    virtual float Perimeter() const { return 0.0f; }*/

protected:
    std::string * m_label;
};

#endif
