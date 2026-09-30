
#include "Pixel.h"

Pixel::Pixel(char symbol, int x, int y) {

    this->symbol = symbol;
    this->X = x;
    this->Y = y;
}
void Pixel::set_symbol(char symb) {
    this->symbol = symb;
}
void Pixel::set_color(std::string color) {this->color = color;}
bool Pixel::is_here(int x, int y) { return this->Y == y && this->X == x;}