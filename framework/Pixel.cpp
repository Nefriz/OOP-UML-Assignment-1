
#include "Pixel.h"

#include <iostream>

Pixel::Pixel(int depth) {
    this->depth = depth;
    this->symbol = " ";
}
void Pixel::set_symbol(std::string symb, int depth) {
    if (this->depth <= depth){this->symbol = symb; this->depth = depth;}
}
void Pixel::set_color(std::string color, int depth) {
    if (this->depth <= depth) {this->color = color; this->depth = depth;}
}

void Pixel::draw() {
    std::cout << this->color << this->symbol << "\033[0m";
}