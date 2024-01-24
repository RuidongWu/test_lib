project(eigen_ex2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)
find_package(Eigen3 REQUIRED CONFIG)

if(TARGET Eigen3::Eigen)
    message(STATUS "Eigen3 v${EIGEN3_VERSION_STRING} found in ${EIGEN3_INCLUDE_DIR}")
endif()

add_executable(linear2 linear2.cpp)
find_package(BLAS)
if(BLAS_FOUND)
    message(STATUS "Eigen will use some subroutines from BLAS.")
    target_compile_definitions(linear2 PRIVATE EIGEN_USE_BLAS)
    target_link_libraries(linear2 PUBLIC ${BLAS_LIBRARIES})
else()
    message(STATUS "BLAS not found. Using Eigen own functions")
endif()
target_link_libraries(linear2 PUBLIC Eigen3::Eigen OpenMP::OpenMP_CXX)
