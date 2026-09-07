#include <iostream>

class Base {
    public:
        virtual void display() {
            std::cout << "Base class display function" << std::endl;
        }
};

class A : public Base {
    public:
        void display() override {
            std::cout << "Class A display function" << std::endl;
        }
};

class B : public Base {
    public:
        void display() override {
            std::cout << "Class B display function" << std::endl;
        }
};

class C : public A, public B {
    public:
        void display() override {
            A::display(); // Calls A's display function
        }
};


int main() {
    C* objC = new C();
    objC->display(); // Calls A's display function due to the order of inheritance

    return 0;
}   
