//
// Created by JoachimWagner on 29.10.2025.
//

#pragma once
#include "AbstractBankNode.h"
namespace composite {
    class Konto : public AbstractBankNode {
    public:
        using AbstractBankNode::AbstractBankNode;

        void print(std::ostream &os) const override {
            os << std::string{"Konto: "};
            AbstractBankNode::print(os);
            os << " Saldo: " << getSaldo();
        }

        double getSaldo() const {
            return saldo;
        }

        void setSaldo(double saldo) {
            Konto::saldo = saldo;
        }



    private:
        double saldo{0};
    };
}
