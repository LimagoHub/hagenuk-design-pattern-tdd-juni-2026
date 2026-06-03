//
// Created by JoachimWagner on 03.06.2026.
//

#include "StapelTest.h"

TEST_F(StapelTest, isEmpty__EmptyStack__returnsTrue) {

    EXPECT_TRUE(objectUnderTest.isEmpty());
}

TEST_F(StapelTest, isEmpty__NotEmptyStack__returnsFalse) {

    objectUnderTest.push(10);
    EXPECT_FALSE(objectUnderTest.isEmpty());
}

TEST_F(StapelTest, push__fillUpToLimit__NoExceptionIsThrown) {

    fillUpToLimit();
}

TEST_F(StapelTest, push__OverFlow1__ThrowsStapelException) {

    try {
        fillUpToLimit();
        objectUnderTest.push(10);
        FAIL() << "Expected StapelException";
    } catch (StapelException& e) {
        EXPECT_STREQ(e.what(), "Overflow");
    }
}
TEST_F(StapelTest, push__OverFlow2__ThrowsStapelException) {


        fillUpToLimit();
        EXPECT_THAT([&]() { this->objectUnderTest.push(1); },
           ThrowsMessage<StapelException>(HasSubstr("Overflow")));

}

void StapelTest::fillUpToLimit() {
    for (int i = 0; i < 10; i++) {
        EXPECT_NO_THROW(objectUnderTest.push(i));
    }
}
