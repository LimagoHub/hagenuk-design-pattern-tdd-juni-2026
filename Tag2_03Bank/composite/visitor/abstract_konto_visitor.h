//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once
#include "konto_visitor.h"
#include "../Konto.h"
#include "../KontoGruppe.h"
namespace composite::visitor {
    class abstract_konto_visitor: public konto_visitor {
    public:
        virtual ~abstract_konto_visitor() = default;

        void init() override {
            // NOP
        }

        void dispose() override {
            // NOP
        }

        void visit(Konto &konto) override {
            // NOP
        }

        void visit(KontoGruppe &konto) override {
            // NOP
        }
    };
}
