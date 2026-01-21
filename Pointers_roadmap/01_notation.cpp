#include <iostream>

using namespace std;

int main() {

  int *p; //Declaring a pointer to integer. Uninitialized. use cout << p << endl; to get an address which means nothing. 
  // use cout<< *p<<endl; to get a garbage value.

  int a = 5;

  p = &a;   // p takes an address variable as input. & before anything will give you an address. &p will give address of p. 
  
  cout<<*p<<endl;   //Now notations in c++ might be confusing at places.
  // Here `*p` dereferences the pointer `p`, meaning it accesses the value
  // stored at the memory address that `p` points to, and prints that value.


  return 0;
}