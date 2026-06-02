cmake_minimum_required(VERSION 4.1)
project(Memento)

set(CMAKE_CXX_STANDARD 20)

add_executable(Memento main.cpp
        tiere/Schwein.h
        tiere/SchweineMemento.h)
