cmake_minimum_required(VERSION 4.1)
project(decorator)

set(CMAKE_CXX_STANDARD 20)

add_executable(decorator main.cpp
        math/CalculatorImpl.h
        math/Calculator.h
        client/CalcClient.h
        math/CalculatorLogger.h
        math/CalculatorSecure.h
        math/CalculatorFactory.h)
