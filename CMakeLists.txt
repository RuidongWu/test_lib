cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message("Setting build type to 'RelWithDebInfo' as none was specified.")
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

message(${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set CXX compile string" FORCE)
message(${CMAKE_CXX_FLAGS})

project(hello_lib)

add_library(hello_lib SHARED src/Hello.cpp)
add_library(hello::lib ALIAS hello_lib)

target_include_directories(hello_lib PUBLIC ${PROJECT_SOURCE_DIR}/inc)

find_package(Boost REQUIRED COMPONENTS filesystem system)
if(Boost_FOUND)
    message("boost found")
else()
    message("cannot find Boost")
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

target_link_libraries(hello_bin PRIVATE hello::lib)