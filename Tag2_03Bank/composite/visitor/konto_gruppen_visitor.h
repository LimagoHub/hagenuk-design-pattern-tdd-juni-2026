//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once

#include <iostream>
#include "abstract_konto_visitor.h"
#include "../Konto.h"

namespace composite::visitor {
    class konto_gruppen_visitor :public abstract_konto_visitor{

        double saldo;
    public:
        void init() override {
            saldo = 0;
        }

        void dispose() override {
            std::cout << saldo << std::endl;
        }

        void visit(Konto &konto) override {
            saldo += konto.getSaldo();
        }
        double getSaldo() {
            return saldo;
        }
    };
}
