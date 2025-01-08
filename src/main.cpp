#include <string>
#include <iostream>

#include "command.h"
#include "sh_commands.h"
#include "tokenizer.h"
int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;


  std::vector<command> valid_commands = load_commands();
  bool run = true;
  int exit_code = 0;
  while (run)
  {
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> args = tokenize(input);
    bool valid_command = false;
    for (int i = 0; i < valid_commands.size(); i++)
    {
      if (valid_commands[i].name == args[0])
      {
        valid_command = true;
      }
    }
    if (args[0] == "exit")
    {
      run = false;
    }
    if (!valid_command)
    {
      std::cout << args[0] << ": " << "command not found" << std::endl;
    }
  }
}
