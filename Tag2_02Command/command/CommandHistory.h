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
        std::stack<CommandPointer> undoStack;
        std::stack<CommandPointer> redoStack;
    public:
        void add(CommandPointer command) {
            if (command->isQuery()) return;

            std::stack<CommandPointer>().swap(redoStack);// Loescht den RedoStack
            undoStack.push(command);
        }

        void undo() {
            if(undoStack.empty()) {
                std::cout << "Can't undo" << std::endl;
            } else {
                auto command = undoStack.top();
                undoStack.pop();
                command->undo();
                redoStack.push(command);
            }
        }

        void redo() {
            if(redoStack.empty()) {
                std::cout << "Can't redo" << std::endl;
            } else {
                auto command = redoStack.top();
                redoStack.pop();
                command->execute();
                undoStack.push(command);
            }
        }
    };
} // command