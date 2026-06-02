//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "AbstractFileProcessor.h"
namespace processor {
    class LineCounter: public AbstractFileProcessor {
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