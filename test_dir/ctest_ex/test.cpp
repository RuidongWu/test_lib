#include "sum_int.hpp"

#include <vector>

int main() {
  auto integers = {1,2,3,4,5};
  if(sum_int(integers) == 15) {
    return 0;
  } else {
    return 1;
  }
}