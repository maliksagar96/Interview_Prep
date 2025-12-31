/*
  Que - What is a unique pointer in c++?
  Ans - unique_ptr was introduced in c++ 11. 
  It disables the copy semantics and only the move is allowed. 
*/

#include <memory> //This library has unique_ptr

//We'll be using the Point class from the first question. 

int main() {
  std::unique_ptr<Point> p1 = std::make_unique<Point>(0.0, 0.0, "Origin");
  std::unique_ptr<Point> p2 = std::move(p1);

}


/*

  Ques - What is a shared_ptr? 
  Ans - It was also introduced in c++ 11. 
  Allows copying and moving. 
  This pointer allows shared ownership of the object via reference counting. 
  The object is destroyed when the last owning shared_ptr is destriyed and reset. 

*/

int main() {
  std::shared_ptr<Point> p1 = std::make_shared<Point>(0,0,"Origin");
  std::shared_ptr<Point> p2 = p1;   //Shared ownership. Change p2 and p1 will also change. 
  std::cout<<"p1 use count = "<<p1.use_count()<<"\n";   //Spits out 2
  std::cout<<"p2 use count = "<<p2.use_count()<<"\n";   //Spits out 2
  
  {
    std::shared_ptr<Point> p3 = p1;
    std::cout<<"p1 use count = "<<p1.use_count()<<"\n";   //Spits out 3
    std::cout<<"p3 use count = "<<p3.use_count()<<"\n";   //Spits out 3
  }

  //p3 is destroyed as the above scope ends. p1 and p2 are alive.

  std::cout<<"p1 use count = "<<p1.use_count()<<"\n";   //Spits out 2

}   //p2 is destroyed and then p1 is destroyed.


/*
  Que - When would you avoid `shared_ptr` in performance-critical code? 
  Ans - It is slow, memory intensive and delays cleanup. 

*/


/*

  Que - When does the compiler auto-generate a move constructor?
  Ans - Whenever the class doesn't define. 
  1) Copy constructor. 2) Copy operator 3) destructor 4) Move constructor 5) Move operator. 
  There should be no virtual declaration of the above member functions as well.

*/