#pragma once
#include <iostream>

namespace utils
{
template<typename Container>
auto print(Container& container)
{
  for(auto& el : container)
  {
    std::cout << el << " ";
  }
    std::cout << std::endl;

}
} // namespace utils
