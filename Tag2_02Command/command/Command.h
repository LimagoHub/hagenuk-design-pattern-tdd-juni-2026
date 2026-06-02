//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include <string>
#include <vector>
using StringVector = std::vector<std::string>;
namespace command {
    class Command {
    public:
        virtual ~Command() = default;
        virtual void parse(StringVector tokens)=0;
        virtual void execute()=0;
        virtual void undo()=0;
        virtual bool isQuery()=0;
    };
} // command