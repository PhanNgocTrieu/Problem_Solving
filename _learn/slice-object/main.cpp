#include <iostream>

using namespace std;

class Animal {
    public:
        virtual void speak() {
            cout << "Animal speaks" << endl;
        }
};

class Dog : public Animal {
    public:
        void speak() override {
            cout << "Dog barks" << endl;
        }
};


void makeSound(Animal* animal) {
    animal->speak();
}

int main() {
    makeSound(new Dog()); // Output: Dog barks
    return 0;
}