//
// Created by JoachimWagner on 01.12.2025.
//

#pragma once

#include <string>
#include "visitor/MitarbeiterVisitor.h"
namespace mitarbeiter {
    using VISITOR=mitarbeiter::visitor::MitarbeiterVisitor;
    class AbstractMitarbeiter {

        std::string name;


    protected:
        explicit AbstractMitarbeiter(const std::string &name) : name(name) {}

    public:
        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            AbstractMitarbeiter::name = name;
        }
        virtual std::string toString() const {
            return "Name = " + getName();
        }
        friend std::ostream &operator<<(std::ostream &os, const AbstractMitarbeiter &abstractMitarbeiter) {
            os << abstractMitarbeiter.toString();
            return os;
        }

        virtual void accept(VISITOR &visitor) = 0;
    };

} // mitarbeiter
