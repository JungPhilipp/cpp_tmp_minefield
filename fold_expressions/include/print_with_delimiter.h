#pragma once

#include <iostream>

namespace fold {

template <class... Ts>
void print_with_delimiter(const char* delimiter, Ts&&... args)
{
  ((std::cout << delimiter << std::forward<Ts>(args)), ...) << std::endl;
}

template <class... Ts>
void print(Ts&&... args)
{
  print_with_delimiter(" ", std::forward<Ts>(args)...);
}

template <class... Ts>
void print_newline(Ts&&... args)
{
  print_with_delimiter("\n", std::forward<Ts>(args)...);
}

} // namespace fold
