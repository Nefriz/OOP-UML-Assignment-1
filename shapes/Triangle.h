//
// Created by 16102 on 30.09.2026.
//

#ifndef ASSIGNMENT01_TRIANGLE_H
#define ASSIGNMENT01_TRIANGLE_H
#include "../framework/Shape.h"
#include "../framework/Board.h"
class Triangle: public Shape {
    private:
    int height;
    public:
    Triangle(int height, bool filled, int x, int y, Board* board, int z,std::string color);
    void draw(Board* board);

};


#endif //ASSIGNMENT01_TRIANGLE_H
