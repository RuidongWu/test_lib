#include "sum_int.hpp"

#include <vector>

int sum_int(const std::vector<int> integers) {
  auto sum = 0;
  for (auto i : integers) {
    sum += i;
  }
  return sum;
}