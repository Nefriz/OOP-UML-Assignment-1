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
    std::vector<std::string> command_history;

    void execute_command(std::string& command);
    void create_object(std::stringstream& stream);
    void save_commands(std::string& filename);
    void load_commands(std::string& filename);
    void help();
    public:
   App();
    void run();
};


#endif //ASSIGNMENT01_APP_H
