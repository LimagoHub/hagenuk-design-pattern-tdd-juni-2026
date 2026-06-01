//
// Created by JoachimWagner on 01.06.2026.
//
//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include "Calculator.h"

namespace math {
    class CalculatorSecure : public Calculator{
    private:
        std::unique_ptr<Calculator> calculator;

    public:
        explicit CalculatorSecure(std::unique_ptr<Calculator> calculator) : calculator(std::move(calculator)) {}


        double add(double a, double b) override {
            std::cout << "Du kommst hier rein" << std::endl;
            return calculator->add(a, b);
        }

        double sub(double a, double b) override {
            std::cout << "sub(" << a << ", " << b << ")" << std::endl;
            return calculator->sub(a, b);
        }
    };
} // math