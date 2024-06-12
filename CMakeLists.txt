cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(include)

add_library(func STATIC src/func.cpp include/func.hpp)

add_library(gd STATIC src/gd.cpp include/gd.hpp)
target_link_libraries(gd func)

add_executable(test_func test/func.cpp)
target_link_libraries(test_func func)

add_executable(test_gd test/gd.cpp)
target_link_libraries(test_gd gd)

add_executable(gradient_descent src/main.cpp include/gd.hpp)
target_link_libraries(gradient_descent gd)

enable_testing()
add_test(test_func test_func)
add_test(test_gd test_gd)

if ( MSVC )
    set_target_properties(gd PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE . )
endif ( MSVC )
