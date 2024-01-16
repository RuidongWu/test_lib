project(opencv_ex)

set(DEFAULT_CXX_STANDARD 11)

set(OpenCV_DIR /usr/lib/x86_64-linux-gnu/pkgconfig)
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    message("OpenCV found")
    MESSAGE(STATUS "    version: ${OpenCV_VERSION}")
    MESSAGE(STATUS "    libraries: ${OpenCV_LIBS}")
    MESSAGE(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(
    ${PROJECT_NAME}
    opencv_ex.cpp
)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

