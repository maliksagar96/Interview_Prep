#include <iostream>

using namespace std;

void fun(const int *p) {
    *p = 0;
}


int main() {

    const int i = 10;
    fun(&i);

    cout<<"i = "<<i<<endl;


    return 0;
}