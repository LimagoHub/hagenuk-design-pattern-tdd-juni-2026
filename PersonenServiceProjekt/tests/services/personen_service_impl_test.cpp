//
// Created by JoachimWagner on 04.06.2026.
//

#include "personen_service_impl_test.h"

#include "../../source/services/personen_service_exception.h"

TEST_F(personen_service_impl_test, speichern__VornameTooShort__throwsPersonenServiceExection) {

    person inValidPerson{"j","Doe"};

    EXPECT_THAT([&]() { this->objectUnderTest.speichern(inValidPerson); },
           ThrowsMessage<personen_service_exception>(StrEq("Vorname zu kurz")));
}

TEST_F(personen_service_impl_test, speichern__NachnameTooShort__throwsPersonenServiceExection) {

    person inValidPerson{"John","D"};

    EXPECT_THAT([&]() { this->objectUnderTest.speichern(inValidPerson); },
           ThrowsMessage<personen_service_exception>(StrEq("Nachname zu kurz")));
}