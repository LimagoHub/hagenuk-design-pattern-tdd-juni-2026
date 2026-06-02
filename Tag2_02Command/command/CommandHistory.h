//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include <iostream>
#include <memory>

#include "Command.h"

namespace command {
    using CommandPointer = std::shared_ptr<Command>;
    class CommandHistory {
    public:
        void add(CommandPointer command) {
            if (command->isQuery()) return;

            // Redos killen
            // Command merken
        }

        void undo() {
            std::cout << "can not Undo" << std::endl;
        }

        void redo() {
            std::cout << "can not redo" << std::endl;
        }
    };
} // command