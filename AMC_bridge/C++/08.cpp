/*

// 8. What is the evaluation order of the function parameters in C++?

Well. The order is not specified.

The following example is a good example. The result in not correct.
No compilation error though.
*/


#include <iostream>

using namespace std;

void foo(int i, int j) {
  cout<< i + j<<endl;
}

int main() {

  int i =0;

  foo(i++, i++);
  

  return 0;
}

