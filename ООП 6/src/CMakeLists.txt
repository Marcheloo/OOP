project(Task_6)

add_library(rpn rpn.cpp)
target_include_directories(rpn PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
