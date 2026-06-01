//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include <iostream>
#include <memory>

#include "../math/Calculator.h"
namespace client {
    class CalcClient {
    public:
        std::unique_ptr<math::Calculator> calculator;



        explicit CalcClient(std::unique_ptr<math::Calculator> calculator) : calculator(std::move(calculator)) {}

        void go() {

            std::cout << calculator->add(1, 2) << std::endl;

        }
    };
} // client