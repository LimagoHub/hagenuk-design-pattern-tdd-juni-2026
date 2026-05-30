#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "myservice_using_dependency_test.h"



// Ein thread-lokaler Pointer auf den Mock
thread_local dependency_to_fake_mock* current_thread_mock = nullptr;


TEST_F(myservice_using_dependency_test, FirstMethod) {
	EXPECT_CALL(dMock, get_firstname()).WillOnce(::testing::Return("Fritz"));

	EXPECT_EQ(object_under_test.first_method_under_test(), "Fritz Hallo");
}

using ::testing::Return;

TEST_F(myservice_using_dependency_test, ShouldReturnMockedName) {


	// 2. Erwartung definieren
	EXPECT_CALL(dMock, get_lastname())
		.WillOnce(Return("Skywalker"));




	// 4. Aufruf der statischen/freien Funktion
	std::string result = dependency_to_fake::get_lastname();

	// 5. Assert
	EXPECT_EQ(result, "Skywalker");


}

/*
 * Linker-Sidetracking (oder Link-Time Subsitution) nutzen, um Legacy Code zu baendigen, der keine Interfaces nutzt.
 *
 */
// Implementierung der Legacy-Methoden
std::string dependency_to_fake::get_firstname() const {
	if (current_thread_mock) return current_thread_mock->get_firstname();
	return "Default Legacy Name";
}

long dependency_to_fake::calculate(const int value) const {
	if (current_thread_mock) return current_thread_mock->calculate(value);
	return 0;
}

// ACHTUNG: Statische Methoden können keine Member-Mocks einfach so nutzen
// Hier musst du den Mock ebenfalls über den TLS-Pointer ansprechen
string dependency_to_fake::get_lastname() {
	if (current_thread_mock) return current_thread_mock->get_lastname();
	return "Default Doe";
}

