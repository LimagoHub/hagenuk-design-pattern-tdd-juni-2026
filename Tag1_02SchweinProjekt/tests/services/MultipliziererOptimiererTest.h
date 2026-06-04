//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once

#include "gmock/gmock.h"

#include "MockMultiplizierer.h"
#include "../../source/services/MultipliziererOptimierer.h"

using namespace testing;
class MultipliziererOptimiererTest: public Test {
protected:
    MockMultiplizierer* multipliziererMock;
    std::unique_ptr<MultipliziererOptimierer> objectUnderTest;
private:
    void SetUp() override {
        auto mock = std::make_unique<MockMultiplizierer>();
        multipliziererMock = mock.get();
        objectUnderTest = std::make_unique<MultipliziererOptimierer>(std::move(mock));
    }
};