//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "CharacterHandler.h"
#include "FileProcessor.h"
namespace processor {
    class CharacterCounter: public CharacterHandler {
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