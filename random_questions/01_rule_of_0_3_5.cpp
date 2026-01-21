/*
There are special member functions associated with the classes in C++. They are
1) Destructor
2) Copy 
3) Move

If we define none of them the compiler automatically defines them efficiently. 
*/

/*
1) Rule of 0
Define none of them. Use RAII types(std::vector, std::string, std::unique_ptr etc.) to own resources. They handle copying, moving and destruction correctly. 
*/

struct SimulationData {
    double time;
    std::vector<double> values;   // ✅ owns its buffer
    std::string name;             // ✅ owns its string
}; 
// → Compiler auto-generates *correct* copy/move/destructor!

/*
2) Rule of 3
If you need to write one of these, then you probably need to write all of these. 
a) Destructor
b) Copying constructor 
c) Copy assignment

*/

#include <cstring>

struct Point {

  Point(double x_, double y_, const char* name):x(x_),y(y_) {
    label = new char[strlen(name) + 1];  
    //Que - Why the label length is +1 long. Ans - It is to accomodate null terminator. '\0'.
    strcpy(label, name);
  }

  double x, y;
  char *label;

  //Destructor to free the label variable on heap.
  ~Point {
    delete[] label;
  }

  //Copy Constructor
  Point(const Point &other): x(other.x), y(other.y){
    label = new char[strlen(other.label) + 1];
    strcpy(label, other.label);
  }

  //Copy assignment operator
  Point& operator=(const Point &other) const {
    if(this != &other) {
      //This has to be given just in case the label is already assigned. 
      /*
      Like Point a(1,2,"a");
        Point b(2,3,"b");
        b = a;
        Since B already has memory assigned to its label if we don't free it first we'll end up loosing the older label memory which will cause memory leak.
      */
      delete[] label;
      x = other.x;
      y = other.y;
      label = new char[strlen(other.label) + 1];
      strcpy(label, other.label);
    }
    return *this;
  }

};

// Note: Move operations are NOT generated (compiler disables them due to user-defined destructor/copy)
// Copying is expensive; moving falls back to copy — Rule of 3 only.

/*
  Rule of 5
  1) Destrcutor. 
  2) Copy Constructor.
  3) Copy assignment.
  4) Move Constructor.
  5) Move assignment.

  Well what the hell is a move assignment?

  Well move assignment is used when we are moving data from one existing object to another pre-exisiting object. We are not constructing a new object. 
  Hence move construtor is not invoked but the move operator. 
  Exampple

  Point p1(1,2,"a");
  Point p2 = std::move(p1); //p2 is not existing this invokes move constructor. 
  Point p3(2,3, "b");
  p3 = std::move(p2);     //p3 is already existing. this invokes the move operator. 

*/

struct Point {
  
  double x, y;
  char *label;

  Point(double x_, double y_, const char* name):x(x_), y(y_) {
    label = new char[strlen(name) + 1];
    strcpy(label, name);    
  }

  Point(Point& other):x(other.x), y(other.y) {
    label = char[strlen(other.label) + 1];
    strcpy(label, other.label);
  }

  //Copy operator
  Point& operator=(const Point &other) const {
    if(this != other) {
      delete[] label;
      x = other.x;
      y = other.y;
      label = new char[strlen(other.label) + 1];
      strcpy(label, other.label);
    }
    return *this;
    
  }

  //move constructor
  Point(Point &&other) noexcept:x(other.x), y(other.y), label(other.label) {
    other.label = nullptr;
  }


  //move operator
  Point& operator=(Point &&other) noexcept {
    if(this != other) {
      delete[] label;
      x = other.x;
      y = other.y;
      label = other.label;  //Stealing the resource. label will copy the address of other.label. And then we are removing the ownership from other in the next line.    
      other.label = nullptr;
    }

    return *this;
  }

  ~Point() {
    delete[] label;
  }

};