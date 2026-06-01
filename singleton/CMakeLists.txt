cmake_minimum_required(VERSION 4.1)
project(singleton)

set(CMAKE_CXX_STANDARD 20)

add_executable(singleton main.cpp
        Singleton.h)
