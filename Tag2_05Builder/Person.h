//
// Created by JoachimWagner on 29.10.2025.
//


#pragma once


#include <string>
#include <ostream>
#include <memory>

class Person {
    std::string id;
    std::string anrede;
    std::string vorname;
    std::string nachname;
    std::string ort;
public:
    Person() = default;
    Person(const std::string &anrede, const std::string &vorname, const std::string &nachname, const std::string &ort)
            : anrede(anrede), vorname(vorname), nachname(nachname), ort(ort) {}

    const std::string &getAnrede() const {
        return anrede;
    }

    void setAnrede(std::string_view &anrede) {
        Person::anrede = anrede;
    }

    const std::string &getVorname() const {
        return vorname;
    }

    void setVorname(std::string_view &vorname) {
        Person::vorname = vorname;
    }

    const std::string &getNachname() const {
        return nachname;
    }

    void setNachname(std::string_view &nachname) {
        Person::nachname = nachname;
    }

    const std::string &getOrt() const {
        return ort;
    }

    void setOrt(std::string_view &ort) {
        Person::ort = ort;
    }


    friend std::ostream &operator<<(std::ostream &os, const Person &person) {
        os << "id: " << person.id << " anrede: " << person.anrede << " vorname: " << person.vorname << " nachname: "
           << person.nachname << " ort: " << person.ort;
        return os;
    }

    class PersonBuilder {
        std::shared_ptr<Person> person{new Person()};
        PersonBuilder() = default;
        friend Person;

    public:
        PersonBuilder & withVorname(std::string_view vorname) {
            person->setVorname(vorname);
            return *this;
        }
        PersonBuilder & withNachname(std::string_view nachname) {
            person->setNachname(nachname);
            return *this;
        }

        PersonBuilder & withAnrede(std::string_view anrede) {
            person->setAnrede(anrede);
            return *this;
        }

        PersonBuilder & withOrt(std::string_view ort) {
            person->setOrt(ort);
            return *this;
        }
        std::shared_ptr<Person> build() {
            // Pruefungen
            return person;
        }
    };
    static PersonBuilder builder () {
        return PersonBuilder{};
    }
};
