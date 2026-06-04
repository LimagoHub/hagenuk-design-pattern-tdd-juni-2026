//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once

#include "gmock/gmock.h"

#include "../../source/services/Multiplizierer.h"


class MockMultiplizierer: public Multiplizierer {
public:
    MOCK_METHOD(unsigned long, mult, (unsigned a, unsigned b), (const, override));
};