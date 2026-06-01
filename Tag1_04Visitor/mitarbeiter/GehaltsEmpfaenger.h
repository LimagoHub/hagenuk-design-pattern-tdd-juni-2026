//
// Created by JoachimWagner on 01.12.2025.
//

#pragma once
#include "AbstractMitarbeiter.h"
namespace mitarbeiter {

    class GehaltsEmpfaenger: public AbstractMitarbeiter {
        double gehalt;
    public:
        GehaltsEmpfaenger(const std::string &name, double gehalt) : AbstractMitarbeiter(name), gehalt(gehalt) {}
        std::string toString() const override {
            return AbstractMitarbeiter::toString() + ", Gehalt = " + std::to_string(gehalt);
        }

        double getGehalt() const {
            return gehalt;
        }

        void setGehalt(double gehalt) {
            GehaltsEmpfaenger::gehalt = gehalt;
        }

        void accept(VISITOR &visitor) override {
            visitor.visit(*this);
        }
    };

} // mitarbeiter
