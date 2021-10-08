cmake_minimum_required(VERSION 3.20)
project(buff)

set(CMAKE_CXX_STANDARD 20)

add_executable(buff main.cpp DynamicVector.cpp Vector.cpp)

