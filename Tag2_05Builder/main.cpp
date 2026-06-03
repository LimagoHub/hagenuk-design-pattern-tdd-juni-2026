#include <iostream>
#include "Person.h"


int main() {

    auto p = Person::builder()
            .withVorname("John")
            .withNachname("Doe")
            .withAnrede("Herr").build();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
