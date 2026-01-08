/*
11. What is the meaning of a const keyword and how can it be used? 

const keyword means read only. And this is used to tell compiler that something that has been initialised should not
be modified again.

*/

#include <iostream>

using namespace std;


class Point {
    double x, double y;

    //Meaning now the method get_x can't change the member variables of the class.
    double get_x() const {
        return x;
    }

    //When and only when we promise not to modify a inside the fucntion.    
    double someFunc(const double &a) {
    }

    //So that we don;t chagne the output of this function somehow. So we return a const double.
    const double someFunc2() {

    }

};


int main () {

    const int x = 5;
    int a = 12;

    // Value of x can't be changed. 
    const int *y; //Value to which y points to can't be changed.

    y = &a;

    //Value of a can be changed through a, not through y
    //*y = 5; //Compilation error.
    a = 3;

    cout<<"Value of *y = "<<*y<<endl;
    cout<<"Value of a = "<<a<<endl;
    
    //This is truly constant. Can't be changed through b or z.
    const int b = 11;
    const int *z = &b;

    int c = 42;
    int *const q = &c;
    
    //Now since the pointer is assigned a constant value, it has to be declared immediately. 
    *q = 33;
    cout<<"*q = "<<*q<<endl;
    cout<<"c = "<<c<<endl;    
    //q = &a;//Can't be reassigned to a new location. The pointer once defined can't be reassigned. 

    return 0;
}
