//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once
namespace composite{
    class Konto;
    class KontoGruppe;
}

namespace composite::visitor {
    class konto_visitor {
    public:
        virtual ~konto_visitor() = default;

        virtual void init()=0;
        virtual void dispose()=0;
        virtual void visit(composite::Konto &konto) = 0;
        virtual void visit(composite::KontoGruppe &kontoGruppe) = 0;
    };
}
