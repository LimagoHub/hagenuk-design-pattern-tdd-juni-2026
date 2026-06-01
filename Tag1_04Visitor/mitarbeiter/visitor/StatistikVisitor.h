//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include <iostream>
#include <ostream>

#include "MitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"

namespace mitarbeiter::visitor {
    class StatistikVisitor: public MitarbeiterVisitor {

    private:
        size_t lohnempfaenger_anzahl=0;
        size_t gehaltsempfaenger_anzahl=0;


    public:
        void init() override {
            gehaltsempfaenger_anzahl=0;
            lohnempfaenger_anzahl=0;
        }

        void visit(mitarbeiter::GehaltsEmpfaenger &gehalts_empfaenger) override {
            gehaltsempfaenger_anzahl++;
        }

        void visit(mitarbeiter::LohnEmpfaenger &lohn_empfaenger) override {
            lohnempfaenger_anzahl++;
        }

        void dispose() override {
            std::cout << *this << std::endl;
        }


        [[nodiscard]] size_t get_lohnempfaenger_anzahl() const {
            return lohnempfaenger_anzahl;
        }

        [[nodiscard]] size_t get_gehaltsempfaenger_anzahl() const {
            return gehaltsempfaenger_anzahl;
        }

        [[nodiscard]] size_t get_mitarbeiter_anzahl() const {
            return get_gehaltsempfaenger_anzahl()+get_lohnempfaenger_anzahl();
        }

        friend std::ostream & operator<<(std::ostream &os, const StatistikVisitor &obj) {
            return os
                   << "lohnempfaenger_anzahl: " << obj.lohnempfaenger_anzahl
                   << " gehaltsempfaenger_anzahl: " << obj.gehaltsempfaenger_anzahl
                   << " mitarbeiter_anzahl: " << obj.get_mitarbeiter_anzahl();
        }
    };
} // visitor