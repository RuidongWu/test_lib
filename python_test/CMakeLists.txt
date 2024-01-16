project(python_test LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)

add_executable(${PROJECT_NAME} embedded_python.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PYTHON_LIBRARIES})

