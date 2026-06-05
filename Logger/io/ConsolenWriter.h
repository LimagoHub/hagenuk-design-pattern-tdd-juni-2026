//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include <iostream>
#include <ostream>

#include "Writer.h"


class ConsolenWriter : public Writer{
public:
    void write(std::string message) override {
        std::cout << message << std::endl;
    }
};
