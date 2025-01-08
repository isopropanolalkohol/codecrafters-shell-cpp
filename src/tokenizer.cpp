//
// Created by joshua on 08.01.25.
//

#include "tokenizer.h"

std::vector<std::string> tokenize(std::string input)
{
  std::vector<std::string> tokens;
  char delimiter = ' ';
  char curr = input[0];
  int index = 1;
  std::string token;
  while (curr != '\0')
  {
    if (curr == delimiter)
    {
      tokens.push_back(token);
      token.clear();
      curr = input[index++];
    }
    else
    {
      token.push_back(curr);
      curr = input[index++];
    }
  }
  tokens.push_back(token);
  return tokens;
}