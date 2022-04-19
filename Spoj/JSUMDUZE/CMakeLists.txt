add_library(JSUMDUZE_lib JSUMDUZE.cpp)
add_executable(JSUMDUZETest JSUMDUZETest.cpp)
target_link_libraries(JSUMDUZETest gtest_main gtest JSUMDUZE_lib)