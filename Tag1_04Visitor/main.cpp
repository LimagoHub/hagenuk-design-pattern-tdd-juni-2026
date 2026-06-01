#include <iostream>
#include "mitarbeiter/GehaltsEmpfaenger.h"
#include "mitarbeiter/LohnEmpfaenger.h"
#include "firma/Firma.h"
#include "mitarbeiter/visitor/PrintVisitor.h"
#include "mitarbeiter/visitor/StatistikVisitor.h"

using GEHALTSEMPFAENGER=mitarbeiter::GehaltsEmpfaenger;
using LOHNEMPFAENGER=mitarbeiter::LohnEmpfaenger;
using FIRMA=firma::Firma;

int main() {
    GEHALTSEMPFAENGER g1("Schmidt", 2000);
    GEHALTSEMPFAENGER g2("Mueller", 1500);
    LOHNEMPFAENGER    lohn1("Hinz", 20, 20);
    LOHNEMPFAENGER    lohn2("Kunz", 15, 20);
    GEHALTSEMPFAENGER g3("Mayer", 1500);

    FIRMA firma;
    firma.add_mitarbeiter(g1);
    firma.add_mitarbeiter(g2);
    firma.add_mitarbeiter(lohn1);
    firma.add_mitarbeiter(lohn2);
    firma.add_mitarbeiter(g3);


    //firma.print();

    //mitarbeiter::visitor::PrintVisitor printVisitor;
    //firma.iterate(printVisitor);

    mitarbeiter::visitor::StatistikVisitor statistik_visitor;
    firma.iterate(statistik_visitor);
    return 0;
}
