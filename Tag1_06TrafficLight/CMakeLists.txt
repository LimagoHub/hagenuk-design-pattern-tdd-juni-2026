cmake_minimum_required(VERSION 3.30)        # Mindest-CMake-Version
project(Tag1_06TrafficLight)                # Projektname

set(CMAKE_CXX_STANDARD 17)                  # C++17 aktivieren

add_executable(Tag1_06TrafficLight          # Ziel: ausführbare Datei
        main.cpp                            # Einstiegspunkt
        trafficlight/TrafficLight.cpp       # Implementierung — MUSS hier stehen!
        trafficlight/state/TrafficLightState.h       # Header (optional, nur für IDE)
        trafficlight/state/AbstractTrafficLightState.h
)