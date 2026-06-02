#include <iostream>
#include <memory>

#include "command/Command.h"
#include "command/CommandFactory.h"
#include "command/CommandHistory.h"
using COMMAND = std::shared_ptr<command::Command>;
int main() {
    command::CommandHistory history;
    std::string line;
    while(true) {
        std::cout << "#>";
        std::getline(std::cin, line);

        if(line == "ende") break;

        if (line == "undo") {
            history.undo();
            continue;
        }

        if (line == "redo") {
            history.redo();
            continue;
        }

        COMMAND command = command::CommandFactory::create(line);

        if (command == nullptr) {
            std::cout << "Invalid command" << std::endl;
            continue;
        }

        command->execute();
        history.add(command);

    }
    return 0;
}