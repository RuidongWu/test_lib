#include "sum_int.hpp"
#include "gtest/gtest.h"

#include <vector>

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(example, sum_zero) {
  auto integers = {1, -1, 2, -2, 3, -3};
  auto result = sum_int(integers);
  ASSERT_EQ(result, 0);
}

TEST(example, sum_five) {
  auto integers = {1, 2, 3, 4, 5};
  auto result = sum_int(integers);
  ASSERT_EQ(result, 15);
}

TEST(example, sum_six) {
  auto integers = {1, 2, 3, 4, 5, 6};
  auto result = sum_int(integers);
  ASSERT_EQ(result, 21);
}

TEST(example, sum_seven) {
  auto integers = {1, 2, 3, 4, 5, 6, 7};
  auto result = sum_int(integers);
  ASSERT_EQ(result, 28);
}

TEST(example, sum_eight) {
  auto integers = {1, 2, 3, 4, 5, 6, 7, 8};
  auto result = sum_int(integers);
  ASSERT_EQ(result, 36);
}