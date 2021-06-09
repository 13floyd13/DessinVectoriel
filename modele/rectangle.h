#ifndef __RECANGLE_H__
#define __RECANGLE_H__

#include "forme.h"
#include "point.h"

#ifndef __MYDRAWINGPANEL__
#include "../view/myDrawingPanel.h"
#endif


class Rectangle: public Forme{
public:
    Rectangle(int x, int y, int w,int h, const std::string& label);
    Rectangle(const Point& p, int w, int h, const std::string& label);
    ~Rectangle();

    void SetCorner(const Point& p);
    void SetWidth(int w);
    void SetHeight() const;

    const Point& GetCorner() const;         // On retourne une r�f�rence const sur m_corner
    int GetWidth() const;
    int GetHeight() const;

    void Move(int dX, int dY);                  // d�place le rectangle
    bool IsInside(const Rectangle &r) const;    // v�rifie l'inclusion
   // virtual void Display(MyDrawingPanel drawingPanel) const override;
    virtual float Surface() const override;
    virtual float Perimeter() const override;

private:
    Point m_corner;
    int m_w;
    int m_h;
  //  MyDrawingPanel drawingPanel;


};


#endif