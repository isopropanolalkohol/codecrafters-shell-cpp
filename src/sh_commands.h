//
// Created by joshua on 08.01.25.
//

#ifndef SH_COMMANDS_H
#define SH_COMMANDS_H
#include <vector>
#include <filesystem>
#include <cstring> //this shit is necessary even though my analyzer lists this as unnecessary import stupid piece of algorithm I need it in my .cpp file
#include "command.h"
COMMAND_RESULT cmd_exit(std::vector<std::string> args);
COMMAND_RESULT cmd_echo(std::vector<std::string> args);
COMMAND_RESULT cmd_type(std::vector<std::string> args);
COMMAND_RESULT cmd_try(std::vector<std::string> args);
COMMAND_RESULT cmd_pwd(std::vector<std::string> args);
std::vector<command> load_commands();
#endif //SH_COMMANDS_H
