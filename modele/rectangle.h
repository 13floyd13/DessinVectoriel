#ifndef __RECANGLE_H__
#define __RECANGLE_H__

#include "forme.h"
#include "point.h"




class Rectangle: public Forme{
public:
    Rectangle(int x, int y, int w,int h, const std::string& label, int color, int fillColor, int thickness);
    Rectangle(const Point& p, int w, int h, const std::string& label, int color, int fillColor, int thickness);
    ~Rectangle();

    void SetCorner(const Point& p);
    void SetWidth(int w);
    void SetHeight(int h);

    const Point& GetCorner() const;         // On retourne une r�f�rence const sur m_corner
    int GetWidth() const;
    int GetHeight() const;


    bool IsInside(int x, int y) const;    // v�rifie l'inclusion

private:
    Point m_corner;
    int m_w;
    int m_h;
};


#endif
