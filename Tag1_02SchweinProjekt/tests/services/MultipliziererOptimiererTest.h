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
    std::shared_ptr<MockMultiplizierer> multipliziererMock;
    std::unique_ptr<MultipliziererOptimierer> objectUnderTest;
private:
    void SetUp() override {
        multipliziererMock = std::make_shared<MockMultiplizierer>();
        objectUnderTest = std::make_unique<MultipliziererOptimierer>(multipliziererMock);
    }
};