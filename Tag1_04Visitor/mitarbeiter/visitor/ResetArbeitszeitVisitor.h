//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include "AbstractMitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"

namespace mitarbeiter::visitor {
    class ResetArbeitszeitVisitor: public AbstractMitarbeiterVisitor{
    public:
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            lohn_empfaenger.setArbeitszeit(0);
        }
    };
} // visitor