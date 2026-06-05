//
// Created by JoachimWagner on 04.06.2026.
//

#include "personen_service_impl_test.h"
#include <stdexcept>
#include "../../source/services/personen_service_exception.h"

TEST_F(personen_service_impl_test, speichern__VornameTooShort__throwsPersonenServiceExection) {

    person inValidPerson{"j","Doe"};

    EXPECT_CALL(blacklistServiceMock, isBlacklisted(_)).Times(0);
    EXPECT_CALL(repoMock, save_or_update(_)).Times(0);

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

    EXPECT_CALL(blacklistServiceMock, isBlacklisted(_)).WillOnce(Return(true));
    EXPECT_THAT([&]() { this->objectUnderTest.speichern(unerwuentePerson); },
           ThrowsMessage<personen_service_exception>(StrEq("Antipath")));
}


TEST_F(personen_service_impl_test, speichern__UnexpectedExceptionInUnderlyingService__throwsPersonenServiceExection) {

    person validPerson{"John","Doe"};

    EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::runtime_error("Upps")));

    EXPECT_THAT([&]() { this->objectUnderTest.speichern(validPerson); },
           ThrowsMessage<personen_service_exception>(StrEq("Fehler beim Speichern")));
}

TEST_F(personen_service_impl_test, speichern__HappyDay__PersonPassedToRepository) {

    InSequence dummy;
    person captured_person{};
    person validPerson{"John","Doe"};


    EXPECT_CALL(blacklistServiceMock, isBlacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(_)).Times(1).WillOnce(DoAll(SaveArg<0>(&captured_person)));

    /*
     *
    EXPECT_CALL(repoMock, save_or_update(AllOf(
    Property(&person::get_vorname, Eq("John")),
    Property(&person::get_nachname, Eq("Mustermann"))
    ))).Times(1);

    */


    this->objectUnderTest.speichern(validPerson);
    EXPECT_THAT( captured_person.get_vorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.get_nachname(), AnyOf(Eq("Doe"), Eq("Mustermann")));
}

TEST_F(personen_service_impl_test,speichern__HappyPath3__parameterPassedToRepo){

    InSequence dummy;

    // Arrange
    person validPerson{"John", "Doe"};


    EXPECT_CALL(blacklistServiceMock, isBlacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(_)).Times(1).WillOnce(
        [&](const person & p) {
        EXPECT_THAT( p.get_vorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    });

    // Action

    objectUnderTest.speichern(validPerson);


}
