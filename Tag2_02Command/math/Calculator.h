//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once


class Calculator {
    Calculator() = default;
    double memory{0};
    // Copy Move etc delete

    // Will ich nicht
    void set_memory(double memory) {
        this->memory = memory;
    }
public:
    Calculator(const Calculator&) = delete;
    static Calculator& getInstance() {
        static Calculator instance;
        return instance;
    }

    [[nodiscard]] double get_memory() const {
        return memory;
    }



    void add(double value) {
        memory += value;
    }
    void sub(double value) {
        memory -= value;
    }
    void mult(double value) {
        memory *= value;
    }
    void div(double value) {
        memory /= value;
    }
    void clear() {
        memory = 0;
    }

    void print() {
        std::cout << memory << std::endl;
    }
};