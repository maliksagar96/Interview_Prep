/*
  1. What is the difference between a reference and a pointer?
  When we write int *p, we call p is a pointer to int type variable.
  When we write int &r, we call p is a reference to an int type variable.

  Reference varaible can't be declared like just
  int &r;

  This gives a compilation error.

  int &r= lvalue; expects an lvalue on the RHS.

  int *p expects an address on the right hand side. 
  So once declared r and a will be attached till the end of time. r can't be bound again but a pointer can be that the key difference.

*/

#include <iostream>

using namespace std; 

int main() {
  
  
  
  

  int a = 10, b = 20;
  int* p = &a;   // p points to a

  cout<<"Pointing to a hence, *p = "<<*p<<endl;

  p = &b;        // ✅ OK: pointer rebound

  cout<<"Pointing to b hence, *p = "<<*p<<endl;
  
  int c;
  int &r = c; //Aliases. 

  //Address of both the variables are same.
  cout<<&c<<endl;
  cout<<&r<<endl;

  c = 10;
  cout<<r<<endl;

  int &r2 = a;    // r is an alias for a
  // r2 = &b;     // ❌ Compile error
  r2 = b;         // ✅ Assigns 20 to 'a' — does NOT rebind r!


  return 0;
}