//
// Created by martpatr on 09/06/2021.
//

#include "draw.h"

Draw::Draw(){
    std::vector<Rectangle> tabRect;
    std::vector<Cercle> tabCercle;
    std::vector<Forme> tabForm;
}

Draw::~Draw() {}

void Draw::AddRect(Rectangle rectangle) {
    tabRect.push_back(rectangle);
}
void Draw::AddCercle(Cercle cercle) {
    tabCercle.push_back(cercle);
}
void Draw::AddForme(Forme forme) {
    tabForm.push_back(forme);
}
std::vector<Rectangle> Draw::GetRect() {
    return tabRect;
};

std::vector<Cercle> Draw::GetCercle() {
    return tabCercle;
}
std::vector<Forme> Draw::GetForm() {
    return tabForm;
}