//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include <memory>
#include <vector>
#include "Command.h"
#include <string>
#include <regex>

#include "AddCommand.h"
#include "PrintCommand.h"
#include "ClearCommand.h"

namespace command {
    using COMMAND = std::shared_ptr<Command>;
    using StringVector = std::vector<std::string>;
    class CommandFactory {
    public:
        static COMMAND create(std::string line) {
            COMMAND result;
            const StringVector tokens =tokenizeLine(line);
            if(tokens[0] == "Add"){
                result = std::make_shared<AddCommand>();
                result->parse(tokens);
            }
            if(tokens[0] == "Print"){
                result = std::make_shared<PrintCommand>();
                result->parse(tokens);
            }
            if(tokens[0] == "Clear"){
                result = std::make_shared<ClearCommand>();
                result->parse(tokens);
            }
            return result;
        }

    private:
        static StringVector tokenizeLine(const std::string &line) {
            auto const regex = std::regex{R"(\s+)"};
            auto const result = StringVector(
                    std::sregex_token_iterator{std::begin(line), std::end(line), regex, -1},
                    std::sregex_token_iterator{}
            );
            return result;
        }
    };
    };
