//
// Created by joshua on 08.01.25.
//
#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>

class command
{
    public:
        command(std::string cmd_name);
        std::string name;
        void exec(std::vector<std::string> args);
};


#endif //COMMAND_H
