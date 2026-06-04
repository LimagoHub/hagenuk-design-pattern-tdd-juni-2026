//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include <memory>
#include "Multiplizierer.h"

class MultipliziererOptimierer: public Multiplizierer {

    std::unique_ptr<Multiplizierer> _multiplizierer;

    public:
    MultipliziererOptimierer(std::unique_ptr<Multiplizierer> multiplizierer) : _multiplizierer(std::move(multiplizierer)) {}
    unsigned long mult(unsigned a, unsigned b) const override {
        if (a < b)
            return _multiplizierer->mult(b, a);
        return _multiplizierer->mult(a, b);

    }
};