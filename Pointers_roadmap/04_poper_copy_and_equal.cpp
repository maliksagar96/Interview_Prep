#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Point {
  public:
  double x, y;
  char *label;

  //Constructor
  Point(double x_, double y_, string name): x(x_), y(y_) {
    label = new char[name.length() + 1];
    strcpy(label, name.c_str());
  }

  Point(const Point &other):x(other.x), y(other.y) {
    label = new char[strlen(other.label) + 1];
    strcpy(label, other.label);
  }

  Point& operator=(const Point& other) {
    if(this != &other) {
      char *newLabel = nullptr;
      if(other.label) {
        newLabel = new char[strlen(other.label) + 1];
        strcpy(newLabel, other.label);
      }

      delete[] label;
      label = newLabel;

      x = other.x;
      y = other.y;    
    }
    return *this;    
  }

  Point(Point &&other) noexcept : x(other.x), y(other.y), label(other.label) {
    other.label = nullptr;
  }

  Point& operator=(Point &&other) noexcept {
    
    if(this != &other) {
      delete[] label;
      x = other.x;
      y = other.y;
      label = other.label;
      other.label = nullptr;
    }

    return *this;
  
  }

  ~Point() {
    delete[] label;
  }
};

int main() {

  return 0;
}