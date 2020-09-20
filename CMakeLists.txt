cmake_minimum_required(VERSION 2.8.12)
project(cmake_example)

add_subdirectory(one-hundred-and-one)
one-hundred-and-one_add_module(cmake_example main.cpp)
