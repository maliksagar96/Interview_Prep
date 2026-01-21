/*
  Well this code tells what the double free is.

*/

#include <iostream> 
#include <string>

using namespace std;

class Point {

  public:

  double x, y;
  string name;

  Point(double x_, double y_, string name_) : x(x_), y(y_), name(name_) {}

  Point(const Point &other):x(other.x), y(other.y), name(other.name){}

  Point& operator=(const Point &other) {
    if(this != &other) {
      x = other.x;
      y = other.y;
      name = other.name;
    }

    return *this;
  }

  ~Point() {}

};

int main() {

  Point *p1 = new Point(1,2,"p1");
  Point *p2 = new Point(2,3,"p2");

  /*This is one way to solve this.*/

  // p2 = p1;
  // p1 = nullptr;

  auto p1 = std::make_unique<Point>(1,2,"p1");
  auto p2 = std::make_unique<Point>(2,3,"p2");
  p2 = std::move(p1);

  cout<<"*******At declaration*********"<<endl;

  cout<<"p2.x = "<<p2->x<<endl;
  cout<<"p2.y = "<<p2->y<<endl;
  cout<<"Name = "<<p2->name<<endl;

  delete p1;

  cout<<"*******After deleting P1*********"<<endl;
  cout<<"p2.x = "<<p2->x<<endl;
  cout<<"p2.y = "<<p2->y<<endl;
  cout<<"Name = "<<p2->name<<endl;

  delete p2;

  return 0;
}