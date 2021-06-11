#ifndef __POINT_H__
#define __POINT_H__

#include <iosfwd>

//-------------------------------------------
class Point
//-------------------------------------------
{
public:
    Point();
    Point(int x, int y);
    Point(int z);
    ~Point();
    void Move(int dX, int dY);

    void SetX(int x);
    void SetY(int y);

    int GetX() const;
    int GetY() const;

    void Save(std::ostream f);
    static Point Load(std::istream f);
    float Distance(const Point &p) const;
    float Distance(const Point *p) const;



private:
    int m_x;
    int m_y;
};

#endif

