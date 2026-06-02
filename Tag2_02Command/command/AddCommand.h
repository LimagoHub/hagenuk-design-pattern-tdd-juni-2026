//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "Command.h"
#include "../math/Calculator.h"
namespace command {
    class AddCommand: public Command {
        double value{0};
    public:
        void parse(StringVector tokens) override {
            value = std::stod(tokens[1]);
        }

        void execute() override {
            Calculator::getInstance().add(value);
        }

        void undo() override {
            Calculator::getInstance().sub(value);
        }

        bool isQuery() override {
            return false;
        }
    };
} // command