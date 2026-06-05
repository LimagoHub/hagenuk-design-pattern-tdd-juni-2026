cmake_minimum_required(VERSION 4.1)
project(Logger)

set(CMAKE_CXX_STANDARD 20)

add_executable(Logger main.cpp
        logger/Logger.h
        io/Writer.h
        io/ConsolenWriter.h)
