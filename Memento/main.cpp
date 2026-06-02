#include <iostream>

#include "tiere/Schwein.h"

int main() {
    tiere::Schwein schwein{"Miss Piggy"};
    std::cout << schwein << std::endl;


    auto zustand = schwein.getMemento();
    schwein.fuettern();

    std::cout << schwein << std::endl;

    schwein.setMemento(zustand);

    std::cout << schwein << std::endl;
    return 0;
}
