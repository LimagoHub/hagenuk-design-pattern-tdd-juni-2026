//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include <iostream>
#include <ostream>

#include "AbstractState.h"


class StateB: public  AbstractState {

    using AbstractState::AbstractState;

    void drucken() override {
        std::cout << "Hier druckt B" << std::endl;
    }

    void changeToA() override {
        getBusiness()->current=getBusiness()->stateA;
    }
};
