//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include <iostream>
#include <string>


class Writer;

class Logger {

    Writer &writer;

    public:
    explicit Logger(Writer &writer)
        : writer(writer) {
    }

    void log(std::string message) {
        const std::string prefix = "Logger: ";
        writer.write(prefix + message);
    }
};
