//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once


class Stapel {

private:
    bool empty{true};
public:

    bool isEmpty() {
        return empty;
    }

    void push(int value) {
        empty = false;
    }
};