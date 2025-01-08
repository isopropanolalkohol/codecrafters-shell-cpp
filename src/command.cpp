//
// Created by joshua on 08.01.25.
//

#include "command.h"

command::command(std::string cmd_name, std::function<COMMAND_RESULT (std::vector<std::string>)> cmd_func)
{
  name = cmd_name;
  cmd_function = cmd_func;
}
COMMAND_RESULT command::exec(std::vector<std::string> args)
{
  return cmd_function(args);
}