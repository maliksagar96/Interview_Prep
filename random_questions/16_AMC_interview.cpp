/*
  Write the constructor for child class.
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
  
  // Child() = default; // Default construtor 

  //With default Cons of mem varible.
  Child() : mem() {

  }

  //CTor with m as input
  Child(const Member &m):mem(m){ 

  }

  //In the copy constructor it is very necessary to explicitly call the base 
  Child(const Child &other) : Base(other), mem(other.mem) {}

  Child& operator=(const Child &other) {
    if(this != &other) {
      Base::operator=(other);
      mem = newMem;
    }

    return *this;
  }

  //DTor here // No need to call destructor of m. It will be called automatically.
  ~Child() override {

  }

};

int main() {

  // Child child;   // Que - 1

  Base *child2 = new Child(); // Que -2 - Is there any difference between output 1 and output 2?

  delete child2 ;

  return 0;

}