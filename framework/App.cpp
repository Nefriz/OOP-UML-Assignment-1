//
// Created by 16102 on 01.10.2026.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>
#include "App.h"

#include "Shape.h"
#include "../shapes/Triangle.h"
#include "../shapes/Square.h"
#include "../shapes/Circle.h"


std::unordered_map<std::string, int> commands{
    {"draw", 1},
    {"list", 2},
    {"shapes", 3},
    {"add", 4},
    {"select_by_location", 5},
    {"select_by_id", 6},
    {"remove", 7},
    {"edit", 8},
    {"paint", 9},
    {"move", 10},
    {"clear", 11},
    {"help", 12}
};

App::App() : board(50, 20) {
}

void App::help() {
    std::map<int, std::string> help_commands{
        {1, "draw"},
        {2, "list"},
        {3, "shapes"},
        {4, "add"},
        {5, "select_by_location <x> <y>"},
        {6, "select_by_id <id>"},
        {7, "remove <id>"},
        {8, "edit <params>"},
        {9, "paint <color>"},
        {10, "move <x> <y> <z>"},
        {11, "clear"}
    };

    for (const auto& [number, name] : help_commands) {
        std::cout  << name << '\n';
    }
}

void App::run() {
    std::cout << std::endl << "Program started" << std::endl;
    this->help();
    std::string command;

    while (true) {
        std::getline(std::cin, command);
        if (command.empty()) {
            break;
        }
        if (command == "exit") {
            exit(0);
        }
        execute_command(command);
    }
};

void App::execute_command(std::string command) {
    std::stringstream stream(command);

    std::string action;
    stream >> action;

    switch (commands[action]) {
        case 1:
            board.draw();
            break;

        case 2:
            board.show_list();
            break;

        case 3:
            board.shapes();
            break;

        case 4:
            create_object(stream);
            break;

        case 5: {
            int x, y;
            stream >> x >> y;
            board.select_object(x, y);
            break;
        }

        case 6: {
            int id;
            stream >> id;
            std::cout << id;
            board.select_object_id(id);
            break;
        }

        case 7:
            board.remove_object();
            break;

        case 8: {;
            std::vector<int> params;
            int value;

            while (stream >> value) {
                params.push_back(value);
            }

            board.edit(params);
            break;
        }

        case 9: {
            std::cout << "enter new color" << std::endl;

            std::string color;
            stream >> color;

            board.paint(color);
            break;
        }

        case 10: {
            std::cout << "enter new X & Y & Z" << std::endl;

            int x, y, z;
            stream >> x >> y >> z;

            board.move(x, y, z);
            break;
        }

        case 11:
            board.clear();
            std::cout << "board cleared" << std::endl;
            break;
        case 12:
            this->help();
            break;
        default:
            std::cerr << "Unknown command \"" << command << "\"" << std::endl;
            break;
    }
}

void App::create_object(std::stringstream &stream) {
    std::string type;
    stream >> type;
    Shape* object = nullptr;

    if (type == "triangle") {
        int height, filled, x, y, z;
        std::string color;
        if (!(stream >> height >> filled >> x >> y >> z >> color)) {
            if (height <= 0){std::cout << "Wrong parameters" << std::endl;}
            return;
        }
        object = new Triangle(height, filled, x, y, z,&board, color);
    };
    if (type == "circle") {
        int radius, filled, x, y, z;
        std::string color;
        if (!(stream >> radius >> filled >> x >> y >> z >> color)) {
            if (radius <= 0) {
                std::cout << "Wrong parameters" << std::endl;
                return;
            }
        }
        object = new Circle(radius, filled, x, y, z,&board, color);
    };
    if (type == "square") {
        int height, width, filled, x, y, z;
        std::string color;
        stream >> height >> width >> filled >> x >> y >> z >> color;
        object = new Square(height,width, filled, x, y, z,&board, color);
    }
    if (object != nullptr) {
        board.add_object(object);
        std::cout << std::endl << "object added" << std::endl;
        return;
    }
    std::cout << "Object not found" << std::endl;
}
