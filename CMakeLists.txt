cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message("Setting build type to 'RelWithDebInfo' as none was specified.")
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

project(hello_lib)

add_library(hello_lib SHARED src/Hello.cpp)
add_library(hello::lib ALIAS hello_lib)

target_include_directories(hello_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

find_package(Boost REQUIRED COMPONENTS filesystem system)
if(Boost_FOUND)
    message("boost found")
else()
    message(FATAL_ERROR "cannot find Boost")
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(FFMPEG REQUIRED IMPORTED_TARGET
    libavdevice
    libavfilter
    libavformat
    libavcodec
    libswresample
    libswscale
    libavutil
)
message(PkgConfig::FFMPEG)

add_executable(hello_bin src/main.cpp)
target_compile_definitions(hello_bin PRIVATE EX3)

target_link_libraries(hello_bin PRIVATE hello::lib Boost::filesystem)

add_subdirectory(sub)
add_subdirectory(sub1)
add_subdirectory(sub2)
add_subdirectory(cfg_file)
