#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Point{
  public:
  float x, y;
  char *label;
  int *arr;
  int arr_sz;

  //constructor
  Point(float x_, float y_,const string &name, int *array, int n):x(x_), y(y_), label(nullptr), arr(nullptr), arr_sz(n) {
    label = new char[name.length() + 1];
    strcpy(label, name.c_str());
    arr = new int[n];
    for(int i = 0;i<n;i++) {
      arr[i] = array[i];
    }
  }

  //copy constructor
  Point(const Point &other):x(other.x), y(other.y), arr_sz(other.arr_sz) {
    label = new char[strlen(other.label) + 1];
    strcpy(label, other.label);
    arr = new int[other.arr_sz];
    for(int i = 0;i<other.arr_sz;i++) {
      arr[i] = other.arr[i];
    }

  }

  //assignment operator
  Point& operator=(const Point &other) {
    if(this != &other) {
      x = other.x;
      y = other.y;
      char *copyLabel = nullptr;
      int *newArr = nullptr;
      if(other.label) {
        copyLabel = new char[strlen(other.label) + 1];
        strcpy(copyLabel, other.label);
      }

      if(other.arr_sz >= 0) {
        newArr = new int[other.arr_sz];
        for(int i = 0;i<other.arr_sz;i++) {
          newArr[i] = other.arr[i];
        }
      }

      delete[] label;
      delete[] arr;

      label = copyLabel;
      arr = newArr;
    }

    return *this;
  }
    //Move Constructor
    Point(Point &&other) noexcept :x(other.x), y(other.y), label(other.label), arr(other.arr), arr_sz(other.arr_sz) {
      other.label = nullptr;
      other.arr = nullptr;
    }

    //Move assisgnment 
    Point& operator=(Point &&other) noexcept {
      if(this != &other) {
        x = other.x;
        y = other.y;
        arr_sz = other.arr_sz;
        other.arr_sz = 0;
        label = other.label;
        arr = other.arr;
        other.label = nullptr;
        other.arr = nullptr;
      }
      return *this;
    }

  ~Point() {
    delete[] label;
    delete[] arr;
  }

};

int main() {

  return 0;
}