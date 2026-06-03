cmake_minimum_required(VERSION 4.1)
project(Composite)

set(CMAKE_CXX_STANDARD 20)

add_executable(Composite main.cpp
        composite/AbstractNode.h
        composite/Leaf.h
        composite/Node.h)
