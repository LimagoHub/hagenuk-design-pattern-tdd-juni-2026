//
// Created by JoachimWagner on 04.06.2026.
//

#include "StapelTest.h"

TEST_F(StapelTest, test1) {
    EXPECT_TRUE(objectUnderTest.isEmpty());
}

TEST_F(StapelTest, test2) {
    objectUnderTest.push(1);
    EXPECT_FALSE(objectUnderTest.isEmpty());
}