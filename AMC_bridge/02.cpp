/*

The unsigned int always gives a modulo of the number with 2^N.
For ubuntu x86 systems it is 2^32. The unsigned goes from 0 to 2^32-1. 

The modulo operator of a negative number is just summation of the negative remainder + divisor. 

For Example -9 % 7 is -2. This is the remainder operator. which is by default in c++.
But -9 mod 7 will be 7-2 = 5.

In the same way, unsigned int x = 5 is nothing but 5 mod 2^32. 

so for x = -1, it will be 

-1 + 2^32 = whatever.

*/

#include <iostream>

using namespace std;

int main() {
  
  unsigned int x = -1; 
  std::cout << x;

  return 0;
}

