//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "AbstractQuery.h"
#include "../math/Calculator.h"

namespace command {
    class PrintCommand : public AbstractQuery{
    public:
        void execute() override {
            Calculator::getInstance().print();
        }
    };
} // command