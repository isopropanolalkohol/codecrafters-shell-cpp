//
// Created by joshua on 08.01.25.
//
#include "sh_commands.h"
command sh_exit("exit");



std::vector<command> load_commands()
{
    std::vector<command> commands;
    commands.push_back(command("exit"));
    return commands;
}