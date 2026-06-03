//
// Created by JoachimWagner on 29.10.2025.
//

#pragma once


#include <memory>
#include <vector>
#include <string>
#include <iostream>



namespace composite {
    class AbstractBankNode : public std::enable_shared_from_this<AbstractBankNode> {
    public:
        using AbstractNodeShared = std::shared_ptr<AbstractBankNode>;
        using AbstractNodeWeak = std::weak_ptr<AbstractBankNode>;
        using Children = std::vector<AbstractNodeShared>;



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
            using pointer = AbstractNodeShared;  // or also value_type*
            using reference = AbstractBankNode &;  // or also value_type&

            Iterator(pointer ptr = nullptr)
                    : current_node(ptr) {
                if (current_node == nullptr) {
                    the_end();
                }
            }

            reference operator*() { return *current_node; }

            pointer operator->() { return current_node; }

            // Prefix increment
            Iterator &operator++() {
                if (!is_end()) {
                    get_next_child();
                }
                return *this;
            }

            // Postfix increment
            Iterator operator++(int) {
                Iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            friend bool operator==(const Iterator &a, const Iterator &b) { return a.current_node == b.current_node; };

            friend bool operator!=(const Iterator &a, const Iterator &b) { return a.current_node != b.current_node; };

        private:

            [[nodiscard]]
            auto is_end() const -> bool {
                return (current_node == nullptr);
            }

            auto the_end() -> void {

                depth = -1;
                current_node = nullptr;
            }

            [[nodiscard]]
            auto go_up_to(pointer ptr) -> bool {

                current_node = ptr;
                if (--depth <= 0) {
                    the_end();
                    return false;
                }
                return true;
            }

            auto go_down_to(pointer ptr) -> void {

                current_node = ptr;
                ++depth;
            }

            [[nodiscard]]
            auto get_parent() -> bool {
                parent_node = current_node->getParent().lock();
                return (parent_node != nullptr);
            }

            [[nodiscard]]
            auto get_first_child_of_parent() -> bool {
                const auto &children = parent_node->getChildren();
                if (!children.empty()) {
                    go_down_to(children[0]);
                    return true;
                }
                return false;
            }

            [[nodiscard]]
            auto find_next_sibling() -> bool {
                const auto &children = parent_node->getChildren();
                bool found{false};
                for (auto &child: children) {
                    if (found) {
                        current_node = child; // no depth change
                        return true;
                    }
                    found = (child == current_node);
                }
                return false;
            }

            [[nodiscard]]
            auto get_next_sibling() -> bool {
                if (depth > 0) // stop at root node
                {
                    if (get_parent()) {
                        if (find_next_sibling()) {
                            return true;
                        }
                    }
                }
                return false;
            }

            auto get_next_child() -> void {
                parent_node = current_node;
                if (!get_first_child_of_parent()) {
                    while (!get_next_sibling()) {
                        if (!go_up_to(parent_node)) {
                            the_end();
                            break;
                        }
                    }
                }
            }

        private:
            int depth{0};
            pointer current_node;
            pointer parent_node;
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
            for (auto &item: *this) {
                std::cout << item << std::endl;
            }

        }






    private:


        std::string name_;
        AbstractNodeWeak parent_;

    };
}