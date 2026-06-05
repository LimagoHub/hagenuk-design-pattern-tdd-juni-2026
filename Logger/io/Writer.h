//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include <string>


class Writer {

public:
    virtual ~Writer() = default;
    virtual void write(std::string message) = 0;
};
