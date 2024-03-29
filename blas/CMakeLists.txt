project(blas_test LANGUAGES CXX C Fortran)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FortranCInterface)

FortranCInterface_VERIFY(CXX)

FortranCInterface_HEADER(
    fc_mangle.h
    MACRO_NAMESPACE "FC_"
    SYMBOLS DSCAL DGESV
    )

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

add_library(math "")
target_sources(math PRIVATE CxxBLAS.cpp CxxLAPACK.cpp)

target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(math PUBLIC ${LAPACK_LIBRARIES})

add_executable(linear "")
target_sources(linear PRIVATE linear.cpp)
target_link_libraries(linear PRIVATE math)