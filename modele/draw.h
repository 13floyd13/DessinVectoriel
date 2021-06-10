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
    void AddForme(Forme forme);
    ~Draw();
    std::vector<Forme>GetForm();
    std::vector<Rectangle> GetRect();
    std::vector<Cercle> GetCercle();

private:
std::vector<Rectangle> tabRect;
std::vector<Cercle> tabCercle;
std::vector<Forme> tabForm;
};


#endif //SKELETON_DRAW_H
