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

class myClass{};

class Child:public Base {

  Member mem;
  myClass *obj1;
  std::unique_ptr<myClass> obj2;
  std::shared_ptr<myClass> obj3;
  public:  
  // Child() = default; // Default construtor 
  //With default Cons of mem varible.
  Child() : mem(), obj1(nullptr), obj2(nullptr) {

  }

  //CTor with m as input
  Child(const Member &m, myClass *obj1_, std::unique_ptr<myClass> obj2_ = nullptr, std::shared_ptr<myClass> obj3_ = nullptr):mem(m),obj1(obj1_),obj2(std::move(obj2_)),obj3(obj3_) { 

  }

  //copy constructor
  Child(const Child &other) : Base(other), mem(other.mem), obj1(nullptr), obj2(nullptr), obj3(nullptr) {
    if(other.obj1) {
      obj1 = new myClass(*other.obj1);
    }

    if(other.obj2) {
      obj2 = std::make_unique<myClass>(*other.obj2);
    }

    if(other.obj3) {
      obj3 = std::make_shared<myClass>(*other.obj3);
    }

  }

  // Assignment operator
  Child& operator=(const Child &other) {
    if(this != &other) {
      Base::operator=(other);
      mem = other.mem;
      //We need to make sure that we are doing a deep copy of obj1
      if(other.obj1 != nullptr) {        
        myClass *temp =  new myClass(*other.obj1);//deferencing the value as other.obj1 is a pointer.
        delete obj1;
        obj1= temp;
      }
      else {
        delete obj1;
        obj1 = nullptr;
      }
      
      if(other.obj2) {
        obj2 = new myClass(*other.obj2);
      }

      else {
        obj2 = nullptr;
      }

      if(other.obj3) {
        obj3 = new myClass(*other.obj3);
      }

      else {
        obj3 = nullptr;
      }
    }
    return *this;
  }

  //DTor here // No need to call destructor of m. It will be called automatically.
  ~Child() override {
    delete obj1;
  }

};

int main() {

  // Child child;   // Que - 1
  // Que -2 - Is there any difference between output 1 and output 2?

  Base *child2 = new Child(); 
  delete child2 ;

  return 0;
}