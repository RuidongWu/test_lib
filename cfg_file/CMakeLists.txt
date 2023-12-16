project(cf_ex)

set(cf_ex_VERSION_MAJOR 0)
set(cf_ex_VERSION_MINOR 1)
set(cf_ex_VERSION_PATCH 2)
set(cf_ex_VERSION "${cf_ex_VERSION_MAJOR}.${cf_ex_VERSION_MINOR}.${cf_ex_VERSION_PATCH}")

configure_file(ver.h.in ${PROJECT_BINARY_DIR}/ver.h)
configure_file(path.h.in ${PROJECT_BINARY_DIR}/path.h @ONLY)

add_executable(cf_ex main.cpp)

target_include_directories(
    cf_ex
    PUBLIC
    ${PROJECT_BINARY_DIR}
)
