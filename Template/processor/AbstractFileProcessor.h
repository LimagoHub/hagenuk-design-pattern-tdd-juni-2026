//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
namespace processor {
    class AbstractFileProcessor {
    public:
        AbstractFileProcessor() = default;
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
        protected:

        virtual void init () {
            // ok
        }

        virtual void dispose() {
            // ok
        }

        virtual void process(char ch) = 0;

    };
} // processor