//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "Command.h"
namespace command {
    class AbstractQuery : public Command{
    public:

        void parse(StringVector tokens) override {
            // Ok
        }



        void undo() override {
            throw std::logic_error{"Upps"};
        }

        bool isQuery()  override {
            return true;
        }
    };
} // command