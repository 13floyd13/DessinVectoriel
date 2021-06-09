//
// Created by martpatr on 09/06/2021.
//
#ifndef __DRAW_H__
#define __DRAW_H__



class Draw {
public:
    draw();
    void AddRect(Rectangle rectangle);
    void AddCercle(Cercle cercle);
    ~draw();

private:
std::vector<Rectangle> tabRect;
std::vector<Cercle> tabCercle;

};


#endif //SKELETON_DRAW_H
