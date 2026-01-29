/*

  Write code to declare unique_ptr on heap and stack.

*/

#include <iostream>
#include <memory>

using namespace std;

int main() {

  //Stack 
  std::unique_ptr<int> a = std::make_unique<int>(10);
  cout <<*a << endl;

  return 0;
}