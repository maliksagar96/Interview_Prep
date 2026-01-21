#include <iostream>

using namespace std;


int main() {

  int &nope;  //This gives an error. A reference is not an object. It doesn't take memory. 

  int n = 10;

  int &r = n; // At compilation time the compiler will make sure that n and r refer to the same object. This is compile time concept. 
              // At runtime there is no metadata or extra data stored to track both names.
              // There is no reference arithematic as well.

  return 0;
}