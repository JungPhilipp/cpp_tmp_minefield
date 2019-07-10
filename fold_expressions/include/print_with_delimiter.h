#pragma once

#include <iostream>

namespace fold{

}
template
<class ... Ts>
void print_with_delimiter(Ts&& ...args){
  auto delimiter = " ";
  ((std::cout << delimiter << std::forward<Ts>(args)), ... )<< std::endl;
}
