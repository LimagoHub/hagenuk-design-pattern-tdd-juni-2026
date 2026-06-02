//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include <functional>
#include <ostream>
#include <string>

#include "Tier.h"


class Schwein : public Tier{
    inline static const unsigned MAX_WEIGHT{20};
    std::vector<std::function<void(Schwein *)>> listeners;

    std::string name;
    int gewicht;
    void firePigTooFatEvent() {
        for (const auto &listener: listeners) {
            listener(this);
        }
    }

    inline void set_gewicht(int gewicht) {
        this->gewicht = gewicht;
        if (gewicht>MAX_WEIGHT) firePigTooFatEvent();
    }
public:

    void addPigTooFatListener(const std::function<void(Schwein *)> &listener) {
        listeners.emplace_back(listener);
    }


    explicit Schwein(const std::string &name)
        : name(name), gewicht(10) {
    }

    [[nodiscard]] std::string get_name() const {
        return name;
    }

    void set_name(const std::string &name) {
        this->name = name;
    }

    [[nodiscard]] int get_gewicht() const {
        return gewicht;
    }

    void fuettern() {
        set_gewicht(get_gewicht() + 1);
    }

    friend bool operator<(const Schwein &lhs, const Schwein &rhs) {
        if (lhs.name < rhs.name)
            return true;
        if (rhs.name < lhs.name)
            return false;
        return lhs.gewicht < rhs.gewicht;
    }

    friend bool operator<=(const Schwein &lhs, const Schwein &rhs) {
        return !(rhs < lhs);
    }

    friend bool operator>(const Schwein &lhs, const Schwein &rhs) {
        return rhs < lhs;
    }

    friend bool operator>=(const Schwein &lhs, const Schwein &rhs) {
        return !(lhs < rhs);
    }

    friend std::ostream & operator<<(std::ostream &os, const Schwein &obj) {
        return os
               << "name: " << obj.name
               << " gewicht: " << obj.gewicht;
    }
};
