cmake_minimum_required(VERSION 3.10)
project(LearningCpp)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(GTest.cmake)

add_subdirectory(OopBasics)
add_subdirectory(Spoj)

enable_testing()
