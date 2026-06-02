//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "Command.h"
#include "../math/Calculator.h"

namespace command {
    class ClearCommand :public Command{
        double oldValue{0};
    public:

        void parse(StringVector tokens) override{}
        void execute() override {
            oldValue = Calculator::getInstance().get_memory();
            Calculator::getInstance().clear();
        }

        void undo() override {
            Calculator::getInstance().set_memory(oldValue);
        }

        bool isQuery() override {
            return false;
        }
    };
} // command