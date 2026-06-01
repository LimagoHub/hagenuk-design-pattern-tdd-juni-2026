//
// Created by JoachimWagner on 01.12.2025.
//

#pragma once
#include "AbstractMitarbeiter.h"

namespace mitarbeiter {

    class LohnEmpfaenger: public AbstractMitarbeiter{
        double stundenlohn;
        double arbeitszeit;

    public:
        LohnEmpfaenger(const std::string &name, double stundenlohn, double arbeitszeit) : AbstractMitarbeiter(name),
                                                                                          stundenlohn(stundenlohn),
                                                                                          arbeitszeit(arbeitszeit) {}

        std::string toString() const override {
            return AbstractMitarbeiter::toString() + ", Stundenlohn = " +std::to_string(stundenlohn) + ", Arbeitszeit = " + std::to_string(arbeitszeit);
        }

        double getStundenlohn() const {
            return stundenlohn;
        }

        void setStundenlohn(double stundenlohn) {
            LohnEmpfaenger::stundenlohn = stundenlohn;
        }

        double getArbeitszeit() const {
            return arbeitszeit;
        }

        void setArbeitszeit(double arbeitszeit) {
            LohnEmpfaenger::arbeitszeit = arbeitszeit;
        }

        void accept(VISITOR &visitor) override {
            visitor.visit(*this);
        }
    };

} // mitarbeiter
