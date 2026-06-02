//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include <memory>
#include <ostream>
#include <string>
#include <variant>

#include "SchweineMemento.h"

namespace tiere {
    class Schwein {

        std::string name;
        int gewicht;
        void set_gewicht(int gewicht) {
            this->gewicht = gewicht;
        }

        class MySchweineMemento: public SchweineMemento {
            const std::string name;
            const int gewicht;
        public:
            MySchweineMemento(const std::string &name, const int gewicht) : name(name), gewicht(gewicht) {}


            const std::string &getName() const {
                return name;
            }

            const int getGewicht() const {
                return gewicht;
            }
        };



    public:

        std::shared_ptr<SchweineMemento>  getMemento() const {
            return std::make_shared<MySchweineMemento>(name, gewicht);
        }

        void setMemento(std::shared_ptr<SchweineMemento> memento) {
            auto myMemento = std::dynamic_pointer_cast<MySchweineMemento>(memento);
            set_name(myMemento->getName());
            set_gewicht(myMemento->getGewicht());
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

        friend std::ostream & operator<<(std::ostream &os, const Schwein &obj) {
            return os
                   << "name: " << obj.name
                   << " gewicht: " << obj.gewicht;
        }

        friend bool operator==(const Schwein &lhs, const Schwein &rhs) {
            return lhs.name == rhs.name
                   && lhs.gewicht == rhs.gewicht;
        }

        friend bool operator!=(const Schwein &lhs, const Schwein &rhs) {
            return !(lhs == rhs);
        }
    };
} // tiere