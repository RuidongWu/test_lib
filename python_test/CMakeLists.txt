project(python_test LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_STRING} EXACT REQUIRED)
message(STATUS "python include dirs: ${PYTHON_INCLUDE_DIRS}")
message(STATUS "python libraries: ${PYTHON_LIBRARIES}")

add_executable(${PROJECT_NAME} embedded_python.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PYTHON_LIBRARIES})

execute_process(
    COMMAND ${PYTHON_EXECUTABLE} "-c" "import re, numpy; print(re.compile('/__init__.py.*').sub('',numpy.__file__))"
    RESULT_VARIABLE _numpy_status
    OUTPUT_VARIABLE _numpy_location
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

if(NOT _numpy_status)
    set(NumPy ${_numpy_location} CACHE STRING "Location of Numpy")
endif()

execute_process(
    COMMAND ${PYTHON_EXECUTABLE} "-c" "import numpy; print(numpy.__version__)"
    OUTPUT_VARIABLE _numpy_version
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NumPy
    FOUND_VAR NumPy_FOUND
    REQUIRED_VARS NumPy
    VERSION_VAR _numpy_version
)

message("numpy_found: ${NumPy_FOUND}")
message("numpy_version: ${_numpy_version}")


add_executable(pure_em PureEmbedding.c)
target_include_directories(pure_em PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(pure_em PRIVATE ${PYTHON_LIBRARIES})

add_custom_command(
  OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
                                          ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
  DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
  )

# make sure building pure-embedding triggers the above
# custom command
target_sources(pure_em
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
)