//
// Created by joshua on 08.01.25.
//
#include "sh_commands.h"
COMMAND_RESULT cmd_exit(std::vector<std::string> args)
{
  return EXIT;
}
command sh_exit("exit", cmd_exit);

COMMAND_RESULT cmd_echo(std::vector<std::string> args)
{
  for (int i = 1; i < args.size(); i++)
  {
    std::cout << args[i] << " ";
  }
  std::cout << std::endl;
  return SUCCESS;
}
command sh_echo("echo", cmd_echo);

std::vector<command> load_commands()
{
    std::vector<command> commands;
    commands.push_back(sh_exit);
    commands.push_back(sh_echo);
    return commands;
}