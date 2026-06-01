//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include "Calculator.h"

namespace math {
    class CalculatorLogger : public Calculator{
    private:
        std::unique_ptr<Calculator> calculator;

    public:

        explicit CalculatorLogger(std::unique_ptr<Calculator> calculator) : calculator(std::move(calculator)) {}


        double add(double a, double b) override {
            std::cout << "add(" << a << ", " << b << ")" << std::endl;
            return calculator->add(a, b);
        }

        double sub(double a, double b) override {
            std::cout << "sub(" << a << ", " << b << ")" << std::endl;
            return calculator->add(a, b);
        }
    };
} // math