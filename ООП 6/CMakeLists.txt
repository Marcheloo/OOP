cmake_minimum_required(VERSION 3.18)

project(Task_6)

add_executable(main task6.cpp)

target_link_libraries(main rpn)


add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(googletest)
add_executable(tests tests.cpp)
target_link_libraries(tests rpn)

target_link_libraries(tests)


target_link_libraries(tests gtest gtest_main)
