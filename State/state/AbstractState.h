//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include "State.h"
#include <stdexcept>

class AbstractState : public State{
    Business * business;

public:
    explicit AbstractState(Business *business)
        : business(business) {
    }


    Business *getBusiness() const {
        return business;
    }
public:
    void drucken() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToA() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToB() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }
};
