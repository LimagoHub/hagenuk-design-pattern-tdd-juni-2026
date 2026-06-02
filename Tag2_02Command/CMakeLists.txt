cmake_minimum_required(VERSION 4.1)
project(Tag2_02Command)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tag2_02Command main.cpp
        math/Calculator.h
        command/Command.h
        command/AbstractQuery.h
        command/PrintCommand.h
        command/AddCommand.h
        command/CommandFactory.h
        command/ClearCommand.h
        command/CommandHistory.h)
