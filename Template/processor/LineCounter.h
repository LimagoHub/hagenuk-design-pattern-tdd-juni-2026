//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "FileProcessor.h"
namespace processor {
    class LineCounter: public CharacterHandler {
        int counter{0};

        void init() override {
            counter = 0;
        }

        void process(char ch) override {
            if (ch == '\n')
                counter++;
        }

        void dispose() override {
            std::cout << "LineCounter: " << counter << std::endl;
        }
    };
} // processor