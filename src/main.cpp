#include <string>
#include <iostream>

#include "command.h"
#include "sh_commands.h"
#include "tokenizer.h"
int main(int argc, char* argv[]) {
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
    //std::cout << getenv("PATH")<< std::endl;
    int command_index = -1;
    for (int i = 0; i < valid_commands.size(); i++)
    {
      if (valid_commands[i].name == args[0])
      {
        command_index = i;
        break;
      }
    }
    if (command_index == -1)
    {
      std::cout << args[0] << ": " << "command not found" << std::endl;
    }
    else
    {
      switch (valid_commands[command_index].exec(args))
      {
        case EXIT:
          run = false;
          break;
        case SUCCESS:
          break;
        case ERROR:
          std::cout << "Error occurred" << std::endl;
          break;
      }
    }
  }
}
