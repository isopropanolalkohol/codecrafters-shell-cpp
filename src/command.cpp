//
// Created by joshua on 08.01.25.
//

#include "command.h"
class command
{
    public:
        command();
        std::string name;
        void exec();
};

std::vector<command> load_commands()
{
  std::vector<command> commands;
  return commands;
}