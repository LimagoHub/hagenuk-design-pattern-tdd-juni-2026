//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include <gmock/gmock.h>
#include "Mockpersonen_repository.h"
#include "../../source/services/personen_service_impl.h"
#include "Mockblacklist_service.h"
using namespace testing;

class personen_service_impl_test: public Test {
protected:
    NaggyMock<Mockpersonen_repository> repoMock;
    NiceMock<Mockblacklist_service> blacklistServiceMock;
    personen_service_impl objectUnderTest{repoMock, blacklistServiceMock};

    void SetUp() override {
        ON_CALL(blacklistServiceMock, isBlacklisted(_)).WillByDefault(Return(false));
    }
};