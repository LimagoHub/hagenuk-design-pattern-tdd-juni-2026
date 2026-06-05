//
// Created by JoachimWagner on 14.12.2022.
//

#include "globaltest.h"
#include <iostream>


class Foo {
public:
    void bar() {
        std::cout << mult(7,8.2) << std::endl;
    }
};


TEST(globaltest, mult_demo) {

    const double result = 42.0;
    EXPECT_GLOBAL_CALL(mult,mult(7.0,8.2)).WillOnce(Return(result));
    Foo objectUnderTest;
    objectUnderTest.bar();
}