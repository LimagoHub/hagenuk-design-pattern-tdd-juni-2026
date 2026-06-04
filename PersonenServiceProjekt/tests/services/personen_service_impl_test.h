//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once
#include <gmock/gmock.h>
#include "Mockpersonen_repository.h"
#include "../../source/services/personen_service_impl.h"

using namespace testing;

class personen_service_impl_test: public Test {
protected:
    Mockpersonen_repository repoMock;
    personen_service_impl objectUnderTest{repoMock};
};