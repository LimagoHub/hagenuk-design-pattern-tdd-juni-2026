cmake_minimum_required(VERSION 4.1)
project(Tag2_01Observer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tag2_01Observer main.cpp
        tiere/Tier.h
        tiere/Schwein.h
        propertychanged/PropertyChangedEvent.h
        propertychanged/Observable.h
)
