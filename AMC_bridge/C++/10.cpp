#include <iostream>

using namespace std;

class B;

class A {

    public:
    // B b; //Compilation error. Why a compilation error. Because B b need the complete layout of the class B. B b, requires compiler to reserve the memory for b. 
    // Reference and pointer don't need that information. Pointer takes only 8 bytes to declare.
    B *c;
    /* Reference should be assigned as soon as it is declared. 
    Here however it is just a member declaration. 
    But as soon as an object of class A is created the reference has to be initialised.
    This can be done in the constructor only.*/
    B &b;  

    A(B &obj) :b(obj) {}

};

class B {
    public:
    double x;
};


int main() {

    B obj;
    A a(obj);

    return 0;

}