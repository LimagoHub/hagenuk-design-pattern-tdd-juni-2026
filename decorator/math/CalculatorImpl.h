//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include "Calculator.h"

namespace math {
    class CalculatorImpl :public Calculator{



        public:
        double add(double a, double b) override{

            return a + b;
        }
        double sub(double a, double b) override{
            return add(a, -b);
        }
    };
} // math