/*
12. What is the meaning of a static keyword and how can it be used? 
    It has different meanings given the context.

    1) If it is defined in a class.
    2) If defined in a function.
    3) Global variable. -> can't be used from one .cpp to other.

    The codes for all 3 are given below.

*/

#include <iostream>

using namespace std;

class Counter {
    public:
    static int count;
    static void increment() {count++;}
    Counter() {

        count++;
    }
};

//The object belongs to class in this case.
//Without making an object. 
int Counter::count = 0; //Declaration is required


void cntr() {
    static int calls = 0;   //Initialised only once.
    ++calls;    
    cout<<"Calls = "<<calls<<endl;
}

int main() {

    Counter::increment();
    cout<<Counter::count<<endl;
    
    Counter a;
    cout<<"a.count = "<<a.count<<endl;
    Counter b;
    cout<<"b.count = "<<b.count<<endl;
    //The static member belongs to the class and not to a particular object. Shared by all the instances of that class.

    cntr();
    cntr();
    cntr();


}
