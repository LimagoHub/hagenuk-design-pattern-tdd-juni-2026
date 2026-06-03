#include <iostream>
#include <memory>

class Foo {
public :
    Foo(){
        std::cout << "Ctor Foo" << std::endl;
    }

    virtual ~Foo() {
        std::cout << "Dtor Foo" << std::endl;
    }

    void bar() {
    std::cout << "bar" << std::endl;
    }
};



int foobar(int &a) {
    std::cout << "lvalue variante" << std::endl;
    return a + 1;
}

int foobar(int &&a) {
    std::cout << "rvalue variante" << std::endl;
    return a + 1;
}

auto source() -> std::unique_ptr<Foo> {
    return std::make_unique<Foo>();
}

auto sink(std::unique_ptr<Foo> other) {
    other->bar();
    return other;
}



int main() {
    std::unique_ptr<Foo> foo = source();

    foo = sink(std::move(foo));

    return 0;
}