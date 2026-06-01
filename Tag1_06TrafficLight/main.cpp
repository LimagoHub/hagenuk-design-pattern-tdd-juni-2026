#include <iostream>
#include "trafficlight/TrafficLight.h"

int main() {
    trafficlight::TrafficLight trafficLight;



    for (int i = 0; i < 5; ++i,trafficLight.nextColor()) {
        std::cout << trafficLight.getColor() << std::endl;
    }
    return 0;
}