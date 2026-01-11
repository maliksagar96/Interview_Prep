/*
    14. What is an abstract class? What is the pure virtual function?
    15. How do you create a virtual constructor and virtual destructor for a class? Why would you do it? 
*/

#include <iostream>
#include <string> 

using namespace std;

//This can serve as base class to other objects but can't be used to make an instance.
class Shape {
    public:
    Shape(std::string name):shapeName(name) {
        cout<<"Calling the base class constrcutor.\n";
    }

    std::string shapeName;
    virtual void resizeShape() {}
    
    //This is pure virtual. Because of this the whole class is now abstract. We can't make an instance of this class at all.
    virtual void draw() = 0;
    //If base constructor is not defined then this would cause memory leak.
    //So declaring a virtual destructor is must. But declararing a virtual constructor is compilation error. 
    virtual ~Shape() {
        cout<<"Base class destructor.\n";
    }
};

class Square: public Shape {

    public:
    Square(std::string name, int dimension, int n): Shape(name), side(dimension) {
        allSides = new int[n];
        for(int i = 0;i<n;i++) {
            allSides[i]=1;
        }
        cout<<"Calling constructor from Derived class.\n";
    }

    int side;
    int *allSides;

    void draw() override {
        cout<<"Drawing a square.\n";
    }

    ~Square() {
        cout<<"Square destructor called.\n";
        delete[] allSides;
    }

};

int main() {

    // Shape s1("square"); 
    Square s1("square", 12, 4);
    // s1.draw();
    return 0;
}