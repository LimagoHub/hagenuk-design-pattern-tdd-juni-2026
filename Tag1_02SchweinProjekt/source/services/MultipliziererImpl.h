//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include "Multiplizierer.h"


class MultipliziererImpl :public Multiplizierer{
public:
    unsigned long mult(unsigned a, unsigned b) override{
        unsigned long result = 0;
        for (int i = 0; i < b; i++)
            result += a;
        
        return result;
    }
};
