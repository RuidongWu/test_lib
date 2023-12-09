cmake_minimum_required(VERSION 3.10)

project(hello_lib)

add_library(hello_lib STATIC src/Hello.cpp)
target_include_directories(hello_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

add_executable(hello_bin src/main.cpp)

target_link_libraries(hello_bin PRIVATE hello_lib)
target_include_directories(hello_bin PUBLIC ${PROJECT_SOURCE_DIR}/inc)