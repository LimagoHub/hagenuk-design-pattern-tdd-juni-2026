//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../source/collections/Stapel.h"

using namespace testing;

class StapelTest:public Test{

protected:
    Stapel objectUnderTest;
};