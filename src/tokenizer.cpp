//
// Created by joshua on 08.01.25.
//

#include "tokenizer.h"

std::vector<std::string> tokenize(std::string input)
{
  std::vector<std::string> tokens;
  char delimiter = ' ';
  char sin_qu = '\'';
  char curr = input[0];
  int index = 1;
  std::string token;
  while (curr != '\0')
  {
    if (curr == delimiter)
    {
      while (curr == delimiter)
      {
        curr = input[index++];
      }
      tokens.push_back(token);
      token.clear();
    }
    else if (curr == sin_qu)
    {
      curr = input[index++];
      while (curr != sin_qu && curr != '\0')
      {
        token.push_back(curr);
        curr = input[index++];
      }
      //token.push_back(curr);
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
//black