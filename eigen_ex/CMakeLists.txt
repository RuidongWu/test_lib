project(eigen_ex LANGUAGES CXX)

find_package(Eigen3 REQUIRED CONFIG)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-march=native" _march_native_works)
check_cxx_compiler_flag("-xHost" _xhost_works)

set(_CXX_FLAGS)
if(_march_native_works)
    message(STATUS "Using processor's vector instructions (-march=native compiler flag set)")
    set(_CXX_FLAGS "-march=native")
elseif(_xhost_works)
    message(STATUS "Using processor's vector instructions (-xHost compiler flag set)")
    set(_CXX_FLAGS "-xHost")
else()
    message(STATUS "No suitable compiler flag found for vectorization")
endif()

add_executable(eigen_unopt eigen_ex.cpp)

target_link_libraries(eigen_unopt
    PRIVATE
    Eigen3::Eigen
)

add_executable(eigen_opt eigen_ex.cpp)

target_compile_options(eigen_opt
    PRIVATE
    ${_CXX_FLAGS}
)

target_link_libraries(eigen_opt
    PRIVATE
    Eigen3::Eigen
)
