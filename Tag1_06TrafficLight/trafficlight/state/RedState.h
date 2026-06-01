//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include "AbstractTrafficLightState.h"
namespace trafficlight::state {
    class RedState : public AbstractTrafficLightState {



    public:
        using AbstractTrafficLightState::AbstractTrafficLightState;

        std::string getColor() {
            return "RED";
        }

        void nextColor() {
            getTrafficLight()->current = getTrafficLight()->green;
        }


    };
}
