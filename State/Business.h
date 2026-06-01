//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include <memory>

#include "state/State.h"

class StateA;
class StateB;

class Business {

private:
    const std::shared_ptr<State> stateA;
    const std::shared_ptr<State> stateB;
    std::shared_ptr<State> current;
public:
    Business();

    virtual void drucken() {
        current->drucken();
    }
    virtual void changeToA(){
        current->changeToA();
    }
    virtual void changeToB() {
        current->changeToB();
    }

    friend class StateA;
    friend class StateB;
};