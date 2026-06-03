cmake_minimum_required(VERSION 4.1)
project(Template)

set(CMAKE_CXX_STANDARD 20)

add_executable(Template main.cpp
        processor/FileProcessor.h
        processor/CharacterCounter.h
        processor/CharacterHandler.h)
