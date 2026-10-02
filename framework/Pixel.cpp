
#include "Pixel.h"

#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string> colors = {
    {"black","\033[30m"},
    {"red","\033[31m"},
    {"green","\033[32m"},
    {"yellow","\033[33m"},
    {"blue","\033[34m"},
    {"magenta","\033[35m"},
    {"cyan","\033[36m"},
    {"white","\033[37m"}
};
std::unordered_map<std::string, std::string> symbs = {
    {"black","B"},
    {"red","R"},
    {"green","G"},
    {"yellow","Y"},
    {"blue","B"},
    {"magenta","M"},
    {"cyan","C"},
    {"white","W"}
};

Pixel::Pixel(int depth) {
    this->depth = depth;
    this->symbol = " ";
}
void Pixel::set_symbol(std::string symb, int depth) {
    if (this->depth <= depth){this->symbol = symbs[symb]; this->depth = depth;}
}
void Pixel::set_color(std::string color, int depth) {
    if (this->depth <= depth) {
        this->color = colors[color];
        this->depth = depth;
        set_symbol(color, depth);
    }
}
void Pixel::set_obj_id(int id, int depth) {
    if (this->depth <= depth) {this->obj_id = id; this->depth = depth;}
}

void Pixel::draw() {
    std::cout << this->color << this->symbol << "\033[0m";
}

void Pixel::clear() {
    this->symbol = " ";
    this->color = "\033[0m";
    this->depth = -1;
    this->obj_id = -1;
}

int Pixel::get_obj_id() { return this->obj_id; }