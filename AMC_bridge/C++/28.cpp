#include <iostream>

using namespace std;

class Member{

    public:
    Member() {
        cout<<"Member CTor.\n";
    }

    ~Member() {
        cout<<"Member DTor.\n";
    }
};


class Base {
    public:
    Base() {
        cout<<"Base Class CTor.\n";
    }

    virtual ~Base() {
        cout<<"Base class DTor.\n";
    }
};

class Child: public Base {

 

    public:
       Member member;
    Child() {
        cout<<"Child class CTor.\n";
    }

    ~Child() {
        cout<<"Child class DTor.\n";
    }
};

int main() {

    Child child;

    return 0;
}