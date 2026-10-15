//
// Created by 16102 on 01.10.2026.
//

#pragma once

#include "../framework/Shape.h"
class Square: public Shape {
    private:
    int height;
    int width;
    public:
    Square(int height, int width, int x, int y,int z, bool filled, Board* board,std::string color);
    void draw(Board* board) override;
    bool edit(const std::vector<int>& params) override;
};
