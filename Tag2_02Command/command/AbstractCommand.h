//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include "AbstractCommand.h"

#include "../math/Calculator.h"
#include "../math/CalculatorMemento.h"
#include "Command.h"

using Calc=Calculator;
using CalcMementoPointer=std::shared_ptr<CalculatorMemento>;

namespace command {

    class AbstractCommand: public Command{
        CalcMementoPointer memento;
    public:
        AbstractCommand()=default;
        ~AbstractCommand() override = default;

        auto parse(StringVector tokens)->void override {
            // Ok
        }

        auto undo() -> void final {
            Calc ::getInstance().setMemento(memento);
        }

        auto isQuery()->bool final {
            return false;
        }
        auto execute()->void final  {
            memento = Calc ::getInstance().getMemento();
            doAction();
        }

    protected:
        virtual void doAction() = 0;
    };

} // command

