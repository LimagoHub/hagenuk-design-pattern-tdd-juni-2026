//
// Created by JoachimWagner on 04.06.2026.
//

#include "MultipliziererOptimiererTest.h"

TEST_F(MultipliziererOptimiererTest, mult__a_lt_b__ParameterShouldBeSwapped) {
    EXPECT_CALL(*multipliziererMock, mult(100, 1)).WillOnce(Return(0));
    objectUnderTest->mult(1, 100);
}

TEST_F(MultipliziererOptimiererTest, mult__a_ge_b__ParameterShouldNotBeSwapped) {
    EXPECT_CALL(*multipliziererMock, mult(100, 1)).WillOnce(Return(0));
    objectUnderTest->mult(100, 1);
}