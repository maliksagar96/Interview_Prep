#include <iostream>

using namespace std;

class Parent {
    public:
    virtual void show() {
        cout<<"Parent show.\n";
    }

    protected:
    int age;
};

class Child:private Parent {
    public:
    void show() {
        cout<<"Child Show.\n";
    }

    void set_age(int a) {
        age = a;
        cout<<"Age = "<<age<<endl;
    }
};

int main() {

    Child *c = new Child();
    c->show();
    c->set_age(10)
    return 0;
}