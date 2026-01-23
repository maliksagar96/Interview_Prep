/*
  Que - What is the output of the code?
*/

/*
  This one teaches some very important lessons.

*/

#include <iostream>

using namespace std;

class Member {
  public:
    Member() {
      cout << "Member CTor.\n";      
    }

    ~Member() {
      cout << "Member DTor.\n";
    }
};

class Base {

  public:
    Base() {
      cout << "Base CTor.\n";
    }

    virtual ~Base() {

      cout << "Base DTor.\n";
    }
};


class Child:public Base {

  Member mem;


  public:
  //CTor here
  Child(){

  }


  //DTor here
  ~Child() override {

  }

};

int main() {

  // Child child;   // Que - 1

  Base *child2 = new Child(); // Que -2 - Is there any difference between output 1 and output 2?

  delete child2 ;

  return 0;

}