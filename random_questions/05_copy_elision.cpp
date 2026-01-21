/*
  Que - What is copy elision? What changed in C++17?

  Ans - So what it does is that it creates the value in place instead of copying or moving it again and again. Elision means omission.
        So copy elision means omission of copying.

*/

std::string hello() {
  return "Hello World";
}

//Named return value optimisation
vector<int> NRVOexample() {

  vector<int> result;

  result.push_back(1);
  result.push_back(2);
  result.push_back(3);

  return result;

}

int main() {

  std::string s = hello();
  vector<int> myVector = NRVOexample();

}


/*
  So we think that in the hello world the string created is lets say temp1 = "Hello World".
  Then temp1 is copied to a return value object temp2. 
  This is then set equal to s. 

  s = temp2

  This is not happening after c++ 17. The compiler is forced to create the hello world in place and directly setting s = "Hello world".

  So the rules for copy elision are now fixed. 

  1) It is guaranteed whenever we have a prvalue(pure right value which doesn;t have an address and can't be copied yet.). 
  2) It is optional for NRVO value. Like in NRVO example code. If copy elision is forced then result will be created in place when it is called by myVector to get a vector.

*/

