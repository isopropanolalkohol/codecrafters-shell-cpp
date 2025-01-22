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
  std::vector<command> commands = load_commands();
  for (auto & command : commands)
  {
    if (command.name == args[1])
    {
      std::cout << command.name << " is a shell builtin\n";
      return SUCCESS;
    }
  }
  std::string env_p = std::getenv("PATH");
  std::string current_path = "";
  for (int i = 0; env_p[i] != '\0'; i++)
  {
    switch (env_p[i])
    {
      case ':':
        if (std::filesystem::exists(current_path + "/" + args[1]))
        {
          std::cout << args[1] << " is " << current_path << '/' << args[1] << '\n';
          return SUCCESS;
        }
         current_path = "";
         break;
      default:
         current_path += env_p[i];
         break;
    }
  }
  std::cout << args[1] << ": not found\n";
  return SUCCESS;
}
command sh_type("type", cmd_type);



COMMAND_RESULT cmd_try(std::vector<std::string> args)
{
  char* env_p = std::getenv("PATH");
  char* paths = strtok(env_p, ":");
  while (paths != nullptr)
  {
    std::string current_path = paths;
    if (std::filesystem::exists(current_path + "/" + args[0]))
    {
      //std::cout << args.size() << '\n';
      std::string ex_path = "";//current_path + "/";
      for (auto arg : args)
      {
        //now follows the most shit-crafted only to work code you've ever seen
        int len = arg.size();/*
        for (int i = 0; i < len; i++)
        {
          if (arg[i] == '\"' || arg[i] == '\\'|| arg[i] == '\''  || arg[i] == '\n')
          {
            arg.insert(i, "\\");
            len += 1;
            i += 1;
          }
        }*/
        ex_path += "\'" + arg + "\' ";
      }
      //ex_path = "\'" + ex_path + "\'";
      //std::cout << "the command to be executed: " << ex_path << "\n";
      system(ex_path.c_str());
      return SUCCESS;
    }
    paths = strtok(NULL, ":");
  }
  return ERROR;
}
command sh_try("try", cmd_try);

COMMAND_RESULT cmd_pwd(std::vector<std::string> args)
{
  if (args.size() != 1)
  {
    std::cout << "expected 0 arguments, got more.\n";
  }
  else
  {
    std::string pwd = std::filesystem::current_path().string();
    std::cout << pwd << "\n";
  }
  return SUCCESS;
}
command sh_pwd("pwd", cmd_pwd);

COMMAND_RESULT cmd_cd(std::vector <std::string> args)
{
  if (args.size() != 2)
  {
    std::cout << "expected 1 argument, got more.\n";
    return SUCCESS;
  }
  if (args[1] == "~")
  {
    std::string home = std::getenv("HOME");
    try
    {
      //std::cout << home << "\n";
      std::filesystem::current_path(home);
    }
    catch (std::filesystem::filesystem_error e)
    {
      std::cout << "cd: " << args[1] << ": No such file or directory\n"; //blub
    }
    return SUCCESS;
  }
  else
  {
    try
    {
      std::filesystem::current_path(args[1]);
    }
    catch (std::filesystem::filesystem_error e)
    {
      std::cout << "cd: " << args[1] << ": No such file or directory\n"; //blub
    }

    return SUCCESS;
  }
}
command sh_cd("cd", cmd_cd);

std::vector<command> load_commands()
{
    std::vector<command> commands;
    commands.push_back(sh_exit);
    commands.push_back(sh_echo);
    commands.push_back(sh_type);
    commands.push_back(sh_pwd);
    commands.push_back(sh_cd);
    return commands;
}