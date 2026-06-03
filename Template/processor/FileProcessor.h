//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "CharacterHandler.h"

namespace processor {
    class FileProcessor {
    public:
        FileProcessor() = default;

        void addHandler(CharacterHandler &handler){
            handlers.push_back(std::ref(handler));
        }

        void run(std::string filename) {
            init();

            std::fstream fin(filename, std::ios::in);
            if(! fin.is_open()) {
                std::cout << "Fehler beim Oeffnen von " << filename << std::endl;
                return;
            }
            int ch;

            while( EOF != (ch = fin.get())) {
                process((char) ch);
            }

            fin.close();
            dispose();
        }
    private:
        std::vector<std::reference_wrapper<CharacterHandler>> handlers;
        void init() {
            for (auto const handler: handlers) {
                handler.get().init();
            }
        }
        void process(char c){
            for (auto const handler: handlers) {
                handler.get().process(c);
            }
        }

        void dispose() {
            for (auto const handler: handlers) {
                handler.get().dispose();
            }
        }

    };
} // processor