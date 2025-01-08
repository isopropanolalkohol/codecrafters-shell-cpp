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
        command();
        std::string name;
        void exec();
};
std::vector<command> load_commands();


#endif //COMMAND_H
