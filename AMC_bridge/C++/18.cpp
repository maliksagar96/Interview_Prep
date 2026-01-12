#include <iostream>
using namespace std;

class Base {
public:
    Base() { foo(); }               // Calls Base::foo(), not Derived::foo()
    virtual void foo() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    Derived() {foo();};
    void foo() override { cout << "Derived\n"; }
};

int main() {
    Derived d;  // Output: "Base"
    // d.foo();
}