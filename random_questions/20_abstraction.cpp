/*

Que - What is abstraction?
Ans - Whenever we define any virtual method in the base class = 0 then it is an abstraction. 


Que - When do you use it?
Ans - We use it when there is no solid logic in defining a default virtual method in the base class. 
If I have a base class called shape. Then giving a default area formula to a shape will not make any sense. The base class here has to be abstract in nature.

*/

#include <iostream>
#include <memory>

using namespace std;

// class Shape{

//   public:
//   Shape() = default;
  
//   //Abstract method definition.
//   virtual double area() const = 0;
//   virtual double perimeter() const = 0;
//   virtual ~Shape() = default;

// };

// class Circle : public Shape {
//   double radius;
//   public:
  
//   Circle(double r) : radius(r) {}
//   double area() const override {return 3.1416 * r * r};
//   double perimeter() const override{return 2 * 3.1416 * r};
// };



int main() {

  return 0;
}