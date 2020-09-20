cmake_minimum_required(VERSION 3.6)
project(main CXX C)

add_executable(main main.cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Lbuild/src)


target_link_libraries (main)
