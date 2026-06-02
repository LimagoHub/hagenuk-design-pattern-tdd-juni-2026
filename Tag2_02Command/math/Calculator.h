//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include "CalculatorMemento.h"

class Calculator {
    Calculator() = default;
    double memory{0};
    // Copy Move etc delete

    // Will ich nicht
    void set_memory(double memory) {
        this->memory = memory;
    }

    class MyCalculatorMemento :public CalculatorMemento {
        const double memory;
    public:


        explicit MyCalculatorMemento(const double memory) : memory(memory) {}

        const double getMemory() const {
            return memory;
        }
    };
public:
    Calculator(const Calculator&) = delete;
    static Calculator& getInstance() {
        static Calculator instance;
        return instance;
    }
    const std::shared_ptr<CalculatorMemento> getMemento() const {
        return std::make_shared<MyCalculatorMemento>(memory);
    }

    void setMemento(const std::shared_ptr<CalculatorMemento> &memento) {
        auto myMemento = std::dynamic_pointer_cast<MyCalculatorMemento>(memento);
        set_memory(myMemento->getMemory());
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