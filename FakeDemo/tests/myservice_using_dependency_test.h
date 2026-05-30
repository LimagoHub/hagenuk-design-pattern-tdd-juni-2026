#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <deque>
#include <map>
#include "../my_service_using_dependency.h"

class dependency_to_fake_mock
{
public:
    MOCK_METHOD(std::string, get_firstname,());
    MOCK_METHOD(std::string, get_lastname, ());
    MOCK_METHOD(long, calculate, (const int));
};

extern thread_local dependency_to_fake_mock* current_thread_mock;

class myservice_using_dependency_test : public ::testing::Test {
protected:
    dependency_to_fake_mock dMock; // Instanz pro Test
    my_service_using_dependency object_under_test;

    void SetUp() override {
        // Mock für diesen Thread registrieren
        current_thread_mock = &dMock;
    }

    void TearDown() override {
        // Wichtig: Pointer löschen, damit Folgetests nicht auf Muell zeigen
        current_thread_mock = nullptr;
    }


};
