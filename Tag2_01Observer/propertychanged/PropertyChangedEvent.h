//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once
#include <ostream>
#include <string>

#include "Observable.h"




class PropertyChangedEvent {
public:
    [[nodiscard]] const Observable * get_sender() const {
        return sender;
    }

    [[nodiscard]] std::string get_property_name() const {
        return propertyName;
    }

    [[nodiscard]] std::string get_old_value() const {
        return oldValue;
    }

    [[nodiscard]] std::string get_new_value() const {
        return newValue;
    }

private:
    const Observable *sender;
    const std::string propertyName;
    const std::string oldValue;
    const std::string newValue;

    friend std::ostream & operator<<(std::ostream &os, const PropertyChangedEvent &obj) {
        return os
               << "sender: " << obj.sender
               << " propertyName: " << obj.propertyName
               << " oldValue: " << obj.oldValue
               << " newValue: " << obj.newValue;
    }

    // nur getter

    // StreamOp
public:
    PropertyChangedEvent(const Observable *sender, const std::string &property_name, const std::string &old_value,
        const std::string &new_value)
        : sender(sender),
          propertyName(property_name),
          oldValue(old_value),
          newValue(new_value) {
    }
};
