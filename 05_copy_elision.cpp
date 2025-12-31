/*
  Que - What is copy elision? What changed in C++17?

  So what it does is that it creates the value in place instead of copying or moving it again and again. 

*/

std::string hello() {
  return "Hello World";
}

int main() {

  std::string s = hello();

}

/*
  So we think that in the hello world the string created is lets say temp1 = "Hello World".
  Then temp1 is copied to a return value object temp2. 
  This is then set equal to s. 

  s = temp2

  This is not happening after c++ 17. The compiler is forced to create the hello world in place and directly setting s = "Hello world".

  So the rules for copy elision are now fixed. 

  1) It is guaranteed whenever we have a prvalue(pure right value which doesn;t have an address and can't be copied yet.). 
  2) It is optional for NRVO value.

*/

