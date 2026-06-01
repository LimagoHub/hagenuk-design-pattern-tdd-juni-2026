#include <iostream>

#include "client/CalcClient.h"
#include "math/CalculatorFactory.h"



int main() {

    math::CalculatorFactory::setLogger(true);
    auto calculator = math::CalculatorFactory::create();

    client::CalcClient calcClient{std::move(calculator)};
    calcClient.go();
    return 0;
}
