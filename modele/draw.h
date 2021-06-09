//
// Created by martpatr on 09/06/2021.
//
#ifndef __DRAW_H__
#define __DRAW_H__


#include <vector>
#include "rectangle.h"
#include "cercle.h"

class Draw {
public:
    Draw();
    void AddRect(Rectangle rectangle);
    void AddCercle(Cercle cercle);
    ~Draw();

private:
std::vector<Rectangle> tabRect;
std::vector<Cercle> tabCercle;

};


#endif //SKELETON_DRAW_H
