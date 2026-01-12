/*
21. struct Vector{ int* data; int size; }; Write copy constructor, operator= and destructor for the struct Vector.
*/

#include <iostream>

using namespace std;

struct Vector {

    //This will serve as the array. 
    int *data;
    int size;

    Vector(int sz):size(sz), data(nullptr) {
        if(sz > 0) {
            data = new int[sz];
        }
    }

    Vector(const Vector &other):size(other.size), data(nullptr) {        
        if(other.size > 0) {
            data = new int[other.size];
            for(int i = 0;i<other.size;i++) {
                data[i] = other.data[i];
            }
        }
    }

    Vector& operator=(const Vector &other) {
        
        if(this == &other) return *this;

        delete[] data;
        size = other.size;
        data = nullptr;

        if(size > 0) {
            data = new int[other.size];
            for(int i = 0;i<other.size;i++) {
            data[i] = other.data[i];
            }
        }

        return *this;    
    }

    //Move constructor
    Vector(Vector &&other) noexcept :size(other.size), data(other.data) {
        other.data =  nullptr;
        other.size = 0;
    }

    Vector& operator=(Vector &&other) noexcept {
        if(this == &other) return *this;    
        delete[] data;
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;

        return *this;    
    }

    ~Vector() {
        delete[] data;
    }

};


int main() {

    return 0;
}