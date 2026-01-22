/*
    // 19. What is a template and how is it used? 
    It is used for writing generic code that works with any datatype.
*/

#include <iostream>

using namespace std;


//Function template.
template<typename T>
T sum(T a, T b) {
    return a + b;
}

template<typename T>
class Box {
    public:
    T value;

    T getValue() const{
        return value;
    }

    void setValue(T t) {
        value = t;  
    }

};

int main() {

    cout<<sum(2, 3)<<endl;

    Box<int> intBox;
    Box<double> dBox;

    intBox.value = 10;

    dBox.value = 12.2;
    cout<<intBox.getValue()<<endl;
    cout<<dBox.getValue()<<endl;

    return 0;
}