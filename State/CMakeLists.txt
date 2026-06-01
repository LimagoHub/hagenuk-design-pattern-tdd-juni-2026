cmake_minimum_required(VERSION 4.1)
project(State)

set(CMAKE_CXX_STANDARD 20)

add_executable(State main.cpp
        state/State.h
        state/AbstractState.h
        state/StateA.h
        state/StateB.h
        Business.cpp
        Business.h)
