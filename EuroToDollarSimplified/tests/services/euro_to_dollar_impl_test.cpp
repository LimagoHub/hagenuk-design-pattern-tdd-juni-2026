//
// Created by JoachimWagner on 13.04.2023.
//

#include "euro_to_dollar_impl_test.h"



TEST_F(euro_to_dollar_impl_test, convert__exception_in_underlying_service__throws_std_runtime_error){

        EXPECT_CALL(exchange_rate_service_mock, get_rate_for).WillOnce(Throw("Irgend einen Unsinn"));

        EXPECT_THAT([&]() { std::ignore = object_under_test.convert(10.0); },ThrowsMessage<std::runtime_error>(StrEq("Exchange Rate Service ist nicht erreichbar")));

}
TEST_F(euro_to_dollar_impl_test, convert__happy_day__returnsExpectedDollarValue){

    EXPECT_CALL(exchange_rate_service_mock, get_rate_for("USD")).WillOnce(Return(2.999999999) );
    auto dollar = object_under_test.convert(10.0);
    EXPECT_THAT(dollar, DoubleNear(29.999999999999999, 0.001));
}



