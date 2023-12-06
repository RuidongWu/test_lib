cmake_minimum_required(VERSION 2.8.12)

project(Top)
set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/inc/)