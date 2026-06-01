//
// Created by JoachimWagner on 01.12.2025.
//

#pragma once
#include <iostream>
#include "MitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"
namespace mitarbeiter::visitor {

    class PrintVisitor: public MitarbeiterVisitor {
    public:
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            std::cout << lohn_empfaenger << "\n";
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            std::cout << gehalts_empfaenger << "\n";
        }
    };

} // visitor
