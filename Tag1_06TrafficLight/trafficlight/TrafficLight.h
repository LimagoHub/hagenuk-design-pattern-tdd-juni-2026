//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once

#include <string>
#include <memory>

#include "state/AbstractTrafficLightState.h"


namespace trafficlight::state {
    class GreenState;
    class RedState;


    class TrafficLightState;

}
namespace trafficlight {
    using TRAFFIC_LIGHT_STATE =  std::shared_ptr<trafficlight::state::TrafficLightState>;
    class TrafficLight {
    private:
        const TRAFFIC_LIGHT_STATE red;
        const TRAFFIC_LIGHT_STATE green;


        TRAFFIC_LIGHT_STATE current;
    public:
        TrafficLight();

        std::string getColor();
        void nextColor();



        friend class trafficlight::state::TrafficLightState;
        friend class trafficlight::state::AbstractTrafficLightState;
        friend class trafficlight::state::RedState;
        friend class trafficlight::state::GreenState;



    };

} // trafficlight
