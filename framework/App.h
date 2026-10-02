//
// Created by 16102 on 01.10.2026.
//

#ifndef ASSIGNMENT01_APP_H
#define ASSIGNMENT01_APP_H

#include <string>
#include "../framework/Board.h"

class App {
private:
    Board board;
    void execute_command(std::string command);
    void create_object(std::stringstream& stream);
    void help();
    public:
   App();
    void run();
};


#endif //ASSIGNMENT01_APP_H
