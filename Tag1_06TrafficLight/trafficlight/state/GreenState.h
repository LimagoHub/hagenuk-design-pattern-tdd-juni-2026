//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include <iostream>
#include "AbstractTrafficLightState.h"
namespace trafficlight::state {
    class GreenState : public AbstractTrafficLightState{

    public:
        using AbstractTrafficLightState::AbstractTrafficLightState;

        std::string getColor() {
            return "GREEN";
        }

        void nextColor() {
            getTrafficLight()->current = getTrafficLight()->red;
        }


    };
}
