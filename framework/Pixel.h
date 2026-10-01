//
// Created by 16102 on 30.09.2026.
//

#ifndef ASSIGNMENT01_PIXEL_H
#define ASSIGNMENT01_PIXEL_H
#include <string>


class Pixel {
protected:
    int depth;
    std::string color;
    std::string symbol;
public:
    Pixel(int depth);
    void set_symbol(std::string symb, int depth);
    void set_color(std::string color, int depth);
    void draw();
};


#endif //ASSIGNMENT01_PIXEL_H
