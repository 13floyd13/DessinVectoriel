#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "forme.h"
#include "point.h"





class Cercle : public Forme
{
public:

    //Cercle();
    typedef Forme super;
    Cercle(const Cercle &other);
    Cercle(Point centre, int radius, std::string label, int color, int fillColor, int thickness);


    virtual ~Cercle();

    void SetCenter(Point p);

    const Point & GetCentre() const;
    const int GetRadius() const;
    bool IsInside(int x, int y) const;

   // virtual void Save(std::ostream f,int type);
//    virtual static void Load(std:: istream f);
  //  virtual void Display(MyDrawingPanel drawingPanel) const override;

private:    // Could be protected
    Point m_center;
    int m_radius;

};
#endif