#include <iostream>
#include "command.h"
int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;


  std::vector<command> valid_commands = load_commands();

  while (true)
  {
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    bool valid_command = false;
    for (int i = 0; i < valid_commands.size(); i++)
    {
      if (valid_commands[i].name == input)
      {
        valid_command = true;
      }
    }
    if (!valid_command)
    {
      std::cerr << input << ": " << "command not found" << std::endl;
    }
  }
}
