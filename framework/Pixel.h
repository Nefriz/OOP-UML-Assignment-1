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
    int obj_id;
public:
    Pixel(int depth);
    void set_symbol(std::string symb, int depth);
    void set_color(std::string color, int depth);
    void set_obj_id(int obj_id, int depth);
    void draw();
    void clear();
    int get_obj_id();
};


#endif //ASSIGNMENT01_PIXEL_H
