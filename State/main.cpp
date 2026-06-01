#include <iostream>
#include "Business.h"

int main() {
    Business business;

    business.drucken();

    business.changeToB();

    business.drucken();

    business.changeToB();
    return 0;
}