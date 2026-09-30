//
// Created by 16102 on 30.09.2026.
//

#ifndef ASSIGNMENT01_PIXEL_H
#define ASSIGNMENT01_PIXEL_H
#include <string>


class Pixel {
protected:
    int X;
    int Y;
    std::string color;
    char symbol;
public:
    Pixel(char symbol, int x, int y);
    void set_symbol(char symb);
    void set_color(std::string color);
    bool is_here(int x, int y);
};


#endif //ASSIGNMENT01_PIXEL_H
