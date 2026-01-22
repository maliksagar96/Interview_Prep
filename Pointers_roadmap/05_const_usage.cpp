#include <iostream>

using namespace std;

int main() {

  int a = 10;
  
  //Pointer to constant int. 
  const int *ptr_to_const_int = &a;

  //The value of a can't be changed 
  // *const_ptr = 12; //This is illegal.

  a = 11;
  cout<<*ptr_to_const_int<<endl;

  int b = 25;

  //Reassignment of const_ptr is possible
  ptr_to_const_int = &b;
  cout<<"Value of b through *ptr_to_const_int = "<<*ptr_to_const_int<<endl;

  //This means that the pointer is not constant. Since this is pointer to const int it behaves in such a manner. 


  //Now lets put the pointer on the other side.
  int c = 33;
  int d = 44;
  int* const const_ptr = &c;

  //This is illegal. Once assigned to an address it will stick to that address only.
  // const_ptr = &d;  

  // The value of c can be changed through const_ptr.
  *const_ptr = 55;
  cout << "Value of c = "<< c << endl;

  int e = 66;
  
  const int* const const_ptr_const = &e; //Legal
  //However we can't change the value of e through the pointer. Neither the pointer can be assigned to any other variable

  
  //Every possible entity is constant here. Truly constant.
  const int m = 12;
  const int *const ptr_m = &m;
  


  
}