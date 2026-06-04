//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include "Dependency.h"


class DemoDep : public Dependency{
public:

    void foo(std::string message) const override {

    }

    int bar() const override {
        return 0;
    }

    size_t foobar(std::string message) const override {
        return 0;
    }


};
