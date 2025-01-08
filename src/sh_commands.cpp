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



COMMAND_RESULT cmd_type(std::vector<std::string> args)
{
  const char* env_p = std::getenv("PATH");
  std::string current_path = "";
  std::string current_dir_name = "";
  for (int i = 0; env_p[i] != '\0'; i++)
  {
    switch (env_p[i])
    {
      case '/':
        current_dir_name = "";
        current_path += env_p[i];
        break;
      case ':':
         current_dir_name = "";
         current_path = "";
         break;
      default:
        current_path += env_p[i];
        current_dir_name += env_p[i];
        if (current_dir_name == args[1] && env_p[i+1] == ':')
        {
          std::cout << args[1] << " is " << current_path << std::endl;
          return SUCCESS;
        }
    }
  }
  std::cout << args[1] << ": not found" << std::endl;
  return SUCCESS;
}
command sh_type("type", cmd_type);

std::vector<command> load_commands()
{
    std::vector<command> commands;
    commands.push_back(sh_exit);
    commands.push_back(sh_echo);
    commands.push_back(sh_type);
    return commands;
}