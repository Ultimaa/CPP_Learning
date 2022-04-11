cmake_minimum_required(VERSION 3.10)

# set the project name
project(oopBasics)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

# add the executable
add_executable(ruleOf5 ruleOf5.cpp)