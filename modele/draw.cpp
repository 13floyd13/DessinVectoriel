//
// Created by martpatr on 09/06/2021.
//

#include "draw.h"

Draw::Draw(){
    std::vector<Rectangle> tabRect;
    std::vector<Cercle> tabCercle;
}

void Draw::AddRect(Rectangle rectangle) {
    tabRect.push_back(rectangle);
}
void Draw::AddCercle(Cercle cercle) {
    tabCercle.push_back(cercle);
}
