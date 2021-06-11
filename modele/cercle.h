#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "forme.h"
#include "point.h"





class Cercle : public Forme
{
public:

    //Cercle();
    Cercle(const Cercle &other);
    Cercle(Point centre, int radius, std::string label, std::string color, std::string fillColor, int thickness);


    virtual ~Cercle();


    Cercle &operator=(const Cercle &other);

    const Point& GetCentre();
    const int GetRadius();

    virtual float Surface() const override;
    virtual float Perimeter() const override;
  //  virtual void Display(MyDrawingPanel drawingPanel) const override;

private:    // Could be protected
    Point m_center;
    int m_radius;

};
#endif