//
// Created by JoachimWagner on 04.06.2026.
//

#include "personen_service_impl_test.h"
#include <stdexcept>
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


TEST_F(personen_service_impl_test, speichern__UnerwuenschtePerson__throwsPersonenServiceExection) {

    person unerwuentePerson{"Attila","Der Hunne"};

    EXPECT_THAT([&]() { this->objectUnderTest.speichern(unerwuentePerson); },
           ThrowsMessage<personen_service_exception>(StrEq("Antipath")));
}


TEST_F(personen_service_impl_test, speichern__UnexpectedExceptionInUnderlyingService__throwsPersonenServiceExection) {

    person validPerson{"John","Doe"};

    EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::runtime_error("Upps")));

    EXPECT_THAT([&]() { this->objectUnderTest.speichern(validPerson); },
           ThrowsMessage<personen_service_exception>(StrEq("Fehler beim Speichern")));
}

