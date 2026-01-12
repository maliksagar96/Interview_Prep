#include <iostream>

using namespace std;

//This is pointing to the next address.
void modifyInt(int *a) {
    a++; 
}

void modifyUsingPointer(int *a) {
    *a = *a + 1;
}

void modifyConsfused(int *a) {
    *a++;//This increases the address value, it will point to the next location
    //the correct way to increment the value if (*a)++
}

void modifyInteger(int &a) {
    a++;
}

int main() {
 
    int a = 5;
    // modifyInt(&a);
    // cout<<a<<endl;

    // modifyInteger(a);
    // cout<<a<<endl;

    modifyUsingPointer(&a);
    cout<<a<<endl;
    
    return 0;
}