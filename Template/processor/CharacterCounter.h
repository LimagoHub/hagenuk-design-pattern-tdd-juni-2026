//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "AbstractFileProcessor.h"
namespace processor {
    class CharacterCounter: public AbstractFileProcessor {
        int counter{0};

        void init() override {
            counter = 0;
        }

        void process(char ch) override {
            counter++;
        }

        void dispose() override {
            std::cout << "CharacterCounter: " << counter << std::endl;
        }
    };
} // processor