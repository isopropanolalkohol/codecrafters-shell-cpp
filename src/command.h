//
// Created by joshua on 08.01.25.
//
#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include <functional>
enum COMMAND_RESULT
{
    SUCCESS, ERROR, EXIT
};
class command
{
    public:
        command(std::string cmd_name, std::function<COMMAND_RESULT (std::vector<std::string>)> cmd_function);
        command();
        std::string name;
        std::function<COMMAND_RESULT (std::vector<std::string>)> cmd_function;
        COMMAND_RESULT exec(std::vector<std::string> args);
};




#endif //COMMAND_H
