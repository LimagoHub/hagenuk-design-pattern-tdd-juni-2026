#include <iostream>

#include "AttributedCharacter.h"

int main() {
    auto a1 = AttributedCharacter::createInstance('A', false);
    auto a2 = AttributedCharacter::createInstance('A', false);
    auto a3 = AttributedCharacter::createInstance('A', true);

    std::cout << (a1 == a2) << std::endl;
    std::cout << (a1 == a3) << std::endl;

    return 0;
}
