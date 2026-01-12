//6. What is the difference between new/malloc or delete/free?

/*

  new = memory allocation and constructor call
  delete = memory allocation and destrcutor call

  malloc = only memory assignment
  free = only memory deletio

*/

#include <iostream>

using namespace std;

struct Point {

  double x, y;

  Point(double x_, double y_) : x(x_), y(y_) {
    cout<<"Point Created with x = "<<x<<", y = "<<y<<endl;
  }

  ~Point (){
    cout<<"Point Deleted with x = "<<x<<", y = "<<y<<endl;
  }

};

int main() {

  //Usage of new and delete
  Point *p = new Point(2,3);
  delete p;

  //Usage of malloc
  Point *p1 = (Point*)malloc(sizeof(Point));//Memory allocated

  //Constructor called explicitly.
  new(p1) Point(4,5);
  
  //Destrcutor explicitly called. This has to be done.
  p1->~Point();

  free(p1);

  return 0;
}