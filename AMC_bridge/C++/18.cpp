/*

18. Is it possible to call a virtual function inside of a constructor/destructor? 
Ans : It can be. But expect no polymorphism. Even though override is written.

*/

#include <iostream>
using namespace std;

class Base {
public:
    Base() { foo(); }               // Calls Base::foo(), not Derived::foo()
    virtual void foo() { cout << "Base call.\n"; }
};

class Derived : public Base {
public:
    Derived() {foo();};
    void foo() override { cout << "Derived call.\n"; }
};

int main() {
    Derived d;  // Output: "Base"
    // d.foo();
}