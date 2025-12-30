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
  }

};




// Note: Move operations are NOT generated (compiler disables them due to user-defined destructor/copy)
// Copying is expensive; moving falls back to copy — Rule of 3 only.