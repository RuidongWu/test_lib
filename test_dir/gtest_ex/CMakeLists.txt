project(gtest_prj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(sum_int_lib sum_int.cpp)

add_executable(sum_in main.cpp)
target_link_libraries(sum_in sum_int_lib)

find_package(GTest REQUIRED)
if(GTest_FOUND)
  message(STATUS "GTest is found!")
endif()

add_executable(g_cpp_test test.cpp)
target_link_libraries(g_cpp_test sum_int_lib gtest gtest_main)

enable_testing()

add_test(
  NAME google_test COMMAND g_cpp_test
)


