project(spdlog_file)

find_package(spdlog REQUIRED)
if(spdlog_FOUND)
    message("spdlog found")
else()
    message(FATAL_ERROR "spdlog not found")
endif()

add_executable(spdlog_ex spdlog_ex.cpp)
target_link_libraries(spdlog_ex PRIVATE spdlog::spdlog)