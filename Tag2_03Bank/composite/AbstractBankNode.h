//
// Created by JoachimWagner on 29.10.2025.
//

#pragma once


#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

#include "visitor/konto_visitor.h"


namespace composite {
    class AbstractBankNode : public std::enable_shared_from_this<AbstractBankNode> {
    public:
        using AbstractNodeShared = std::shared_ptr<AbstractBankNode>;
        using AbstractNodeWeak = std::weak_ptr<AbstractBankNode>;
        using Children = std::vector<AbstractNodeShared>;
        using Visitor = visitor::konto_visitor;


        explicit AbstractBankNode(const std::string &name = "undef") : name_(name) {}

        AbstractBankNode(const AbstractBankNode &other) = delete;

        AbstractBankNode(AbstractBankNode &&other) = delete;

        AbstractBankNode &operator=(const AbstractBankNode &other) = delete;

        AbstractBankNode &operator=(AbstractBankNode &&other) = delete;

        virtual ~AbstractBankNode() = default;

        struct Iterator {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = AbstractBankNode;
            using pointer = AbstractNodeShared;
            using reference = AbstractBankNode &;

            Iterator() = default;

            explicit Iterator(pointer root) {
                if (root) stack_.push(root);
            }

            reference operator*() { return *stack_.top(); }
            pointer operator->() { return stack_.top(); }

            Iterator &operator++() {
                pointer node = stack_.top();
                stack_.pop();
                const auto &children = node->getChildren();
                for (auto it = children.rbegin(); it != children.rend(); ++it)
                    stack_.push(*it);
                return *this;
            }

            Iterator operator++(int) {
                Iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            friend bool operator==(const Iterator &a, const Iterator &b) {
                if (a.stack_.empty() && b.stack_.empty()) return true;
                if (a.stack_.empty() || b.stack_.empty()) return false;
                return a.stack_.top() == b.stack_.top();
            }

            friend bool operator!=(const Iterator &a, const Iterator &b) { return !(a == b); }

        private:
            std::stack<pointer> stack_;
        };
        Iterator begin() { return Iterator(shared_from_this()); }

        Iterator end() { return Iterator(); }


        const std::string &getName() const {
            return name_;
        }

        void setName(const std::string &name) {
            name_ = name;
        }

        const AbstractNodeWeak &getParent() const {
            return parent_;
        }

        void setParent(const AbstractNodeWeak &parent) {
            parent_ = parent;
        }

        virtual const Children &getChildren() const {
            static Children dummy{};
            return dummy;
        }


        virtual void print(std::ostream &os) const {
            os << std::string{"name: "} << this->getName();
        }

        friend auto operator<<(std::ostream &os, const AbstractBankNode &node) -> std::ostream & {
            node.print(os);
            return os;
        }

        virtual void ausgabe()  {
            /*std::cout << *this << std::endl;
            for (auto &child: getChildren()) {
                child->ausgabe();
            }
            */
            for(auto & knoten: *this) {
                std::cout << knoten << std::endl;
            }

        }

        void iterate(Visitor &visitor) {
            visitor.init();
            for(auto &item: *this){
                item.accept(visitor);
            }
            visitor.dispose();
        }

    protected:
        virtual void accept(Visitor &visitor) = 0;


    private:


        std::string name_;
        AbstractNodeWeak parent_;

    };
}