//
// Created by 16102 on 01.10.2026.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>
#include "App.h"
#include <fstream>
#include <vector>

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
    {"help", 12},
    {"save", 13},
    {"load", 14}
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
        {11, "clear"},
        {12, "save"},
        {13, "load"},
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

void App::execute_command(std::string& input) {
    std::stringstream stream(input);

    std::string action;
    stream >> action;
    auto command = commands.find(action);
    if (command == commands.end()) {
        std::cout << "Unknown command \"" << action << "\"" << std::endl;
        return;
    }
    switch (command -> second) {
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
            if(create_object(stream)) {
                command_history.push_back(input);
            };
            break;

        case 5: {
            int x, y;
            stream >> x >> y;
            if(board.select_object(x, y)) {
                command_history.push_back(input);
            };
            break;
        }

        case 6: {
            int id;
            stream >> id;
            if(board.select_object_id(id)) {
                command_history.push_back(input);
            };
            break;
        }

        case 7:
            if(board.remove_object()) {
                command_history.push_back(input);
            };
            break;

        case 8: {;
            std::vector<int> params;
            int value;

            while (stream >> value) {
                params.push_back(value);
            }

            if (board.edit(params)) {
                command_history.push_back(input);
            };
            break;
        }

        case 9: {
            std::cout << "enter new color" << std::endl;

            std::string color;
            stream >> color;

            if(board.paint(color)) {
                command_history.push_back(input);
            };
            break;
        }

        case 10: {
            int x, y, z;
            stream >> x >> y >> z;

            if(board.move(x, y, z)) {
                command_history.push_back(input);
            };
            break;
        }

        case 11:
            board.clear();
            command_history.clear();
            std::cout << "board cleared" << std::endl;
            break;
        case 12:
            this->help();
            break;
        case 13: {
            std::string filename;
            stream >> filename;

            save_commands(filename);
            break;
        }

        case 14: {
            std::string filename;
            stream >> filename;

            load_commands(filename);
            break;
        }
        default:
            std::cerr << "Unknown command \"" << input << "\"" << std::endl;
            break;
    }
}

bool App::create_object(std::stringstream &stream) {
    std::string type;
    stream >> type;
    Shape* object = nullptr;

    if (type == "triangle") {
        int height, filled, x, y, z;
        std::string color;
        if (!(stream >> height >> filled >> x >> y >> z >> color)) {
            if (height <= 0){std::cout << "Wrong parameters" << std::endl;}
            return false;
        }
        object = new Triangle(height, filled, x, y, z,&board, color);
    };
    if (type == "circle") {
        int radius, filled, x, y, z;
        std::string color;
        if (!(stream >> radius >> filled >> x >> y >> z >> color)) {
            if (radius <= 0) {
                std::cout << "Wrong parameters" << std::endl;
                return false;
            }
        }
        object = new Circle(radius, x, y, z,filled, &board, color);
    };
    if (type == "square") {
        int height, width, filled, x, y, z;
        std::string color;
        stream >> height >> width >> filled >> x >> y >> z >> color;
        object = new Square(height,width, x, y, z,filled,&board, color);
    }
    if (object != nullptr) {
        if (!board.is_inside(object->get_x(), object->get_y())) {
            std::cout << "Coordinates outside the board" << std::endl;
            delete object;
            return false;
        }
        board.add_object(object);
        std::cout << std::endl << "object added" << std::endl;
        return true;
    }
    std::cout << "Object not found" << std::endl;
    return false;
}
void App::save_commands(std::string& filename) {
    std::ofstream file(filename);

    for (const std::string& command : command_history) {
        std::istringstream stream(command);
        std::string action;
        stream >> action;

        if (action == "save" || action == "load") {
            continue;
        }

        file << command << '\n';
    }
    std::cout << "file saved:" << filename<< std::endl;
}
void App::load_commands(std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return;
    }
    std::vector<std::string> loaded_commands;
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            loaded_commands.push_back(line);
        }
    }
    board.clear();
    command_history.clear();

    for (std::string& command : loaded_commands) {
        execute_command(command);
    }
}