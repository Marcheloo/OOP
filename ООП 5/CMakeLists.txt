cmake_minimum_required (VERSION 3.2)
project (parallel)
SET(CMAKE_CXX_STANDARD 11)

find_package (Threads)

include_directories(include)

add_executable (parallel main.cpp)
target_link_libraries (parallel Threads::Threads)