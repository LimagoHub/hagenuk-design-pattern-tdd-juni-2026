//
// Created by JoachimWagner on 01.06.2026.
//

#pragma once
#include <iostream>

class Singleton {
private:
    Singleton() {
        std::cout << "Test" << "\n";
    };
public:
    Singleton(Singleton const&)               = delete;
    auto operator=(Singleton const&)->void    = delete;

    Singleton(Singleton &&)               = delete;
    auto operator=(Singleton &&)->void    = delete;

    static auto create ()-> Singleton& {

        static Singleton instance ; // Lazy + Threadsafe
        return instance;
    }
    auto log(std::string message)->void{
        std::cout << message << std::endl;
    }
};