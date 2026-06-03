#include <iostream>

#include <memory>
#include "composite/KontoGruppe.h"
#include "composite/Konto.h"
#include "composite/visitor/PrintVisitor.h"

using namespace composite;
int main() {
    auto root = std::make_shared<KontoGruppe>("Root");

    auto e1 = std::make_shared<KontoGruppe>("E1");
    auto e2 = std::make_shared<KontoGruppe>("E2");
    auto e3 = std::make_shared<KontoGruppe>("E3");

    root->append(e1);
    root->append(e2);
    root->append(e3);

    auto e3_1 =  std::make_shared<KontoGruppe>("E3_1");
    auto e3_2 =  std::make_shared<KontoGruppe>("E3_2");
    auto e3_3 =  std::make_shared<KontoGruppe>("E3_3");

    e3->append(e3_1);
    e3->append(e3_2);
    e3->append(e3_3);

    auto e2_1 =  std::make_shared<Konto>("E2_1");
    auto e2_2 =  std::make_shared<Konto>("E2_2");

    e2->append(e2_1);
    e2->append(e2_2);

    /*
    for(auto & knoten: *root) {
        std::cout << knoten << std::endl;
    }
*/
    visitor::PrintVisitor printVisitor;

    root->iterate(printVisitor);

    return 0;
}
