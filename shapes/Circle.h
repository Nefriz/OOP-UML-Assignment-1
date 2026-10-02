//
// Created by 16102 on 01.10.2026.
//

#ifndef ASSIGNMENT01_CIRCLE_H
#define ASSIGNMENT01_CIRCLE_H
#include "../framework/Shape.h"

class Circle: public Shape {
private:
    int radius;
    public:
    Circle(int radius, int x, int y,int z, bool filled, Board* board,std::string color);
    void draw(Board* board) override;
    bool edit(const std::vector<int>& params) override;
};


#endif //ASSIGNMENT01_CIRCLE_H
