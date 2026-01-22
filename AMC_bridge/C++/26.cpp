/*
26. What will happen if the exception will be thrown within a constructor?
Ans - Even though the constructor is called and data and name are fully specified, their destructors will be called autmatically.
No object will be created.

*/


#include <iostream>
#include <cmath>

using namespace std;

class MyClass {
    std::string name;   // constructed first
    int data; // constructed second

public:
    MyClass() : name("test"), data(1000) {
        throw std::runtime_error("Oops!");
        // ← name and data are fully constructed → their destructors WILL run
    }
};

int main() {
    MyClass m;

    return 0;
}