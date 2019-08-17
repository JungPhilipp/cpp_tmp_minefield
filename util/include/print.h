//
// Created by philipp on 8/17/19.
//

#include <export.h>
#include <iostream>

template <class T, class... Ts>
EXPORT auto print_with_delimiter(T&& delimiter, Ts&&... args) -> void
{
  ((std::cout << delimiter << std::forward<Ts>(args)), ...);
}

template <class... Ts>
EXPORT auto print(Ts&&... args) -> void
{
  print_with_delimiter(" ", std::forward<Ts>(args)...);
}

template <class... Ts>
EXPORT auto println(Ts&&... args) -> void
{
  print_with_delimiter("\n", std::forward<Ts>(args)...);
}

template <class... Ts>
EXPORT auto printls(Ts&&... args) -> void
{
  print_with_delimiter("\n---\n", std::forward<Ts>(args)...);
}