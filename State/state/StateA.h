//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include <iostream>
#include <ostream>

#include "AbstractState.h"


class StateA: public  AbstractState {

    using AbstractState::AbstractState;

    void drucken() override {
        std::cout << "Hier druckt A" << std::endl;
    }

    void changeToB() override {
        getBusiness()->current=getBusiness()->stateB;
    }
};
