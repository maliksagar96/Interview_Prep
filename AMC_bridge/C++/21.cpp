/*
21. struct Vector{ int* data; int size; }; Write copy constructor, operator= and destructor for the struct Vector.
*/

#include <iostream>

using namespace std;

struct Vector {

    //This will serve as the array. 
    int *data;
    int size;

    //Constructor
    Vector(int *data_, int sz):data(nullptr), size(sz) {
        if(sz > 0) {
            data = new int[sz];
            for(int i = 0;i<sz;i++) {
                data[i] = data_[i];
            }
        }

        else {
            cout<<"Enter a positive size of the vector.\n";
            exit(0);
        }
    }
    
    //Copy constructor
    Vector(const Vector &other):data(nullptr), size(other.size) {
        if(other.size > 0) {
            data = new int[other.size];
            for(int i = 0;i < other.size;i++) {
                data[i] = other.data[i];
            }            
        }
    }

    //Assignmnet operator
    Vector& operator=(const Vector &other) {
        if(this != &other) {
            size = other.size;
            int *newData = nullptr;
            if(other.size > 0) {
                newData =  new int[other.size];
                for(int i = 0;i<other.size;i++) {
                    newData[i] = other.data[i];
                }
            }
            
            delete[] data;
            data = newData;
        }

        return *this;

    }


    //Move Constructor
    Vector(Vector &&other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
    }

    //Move assignmnet operator
    Vector& operator=(Vector &&other) noexcept {
        if(this != &other) {
            size = other.size;
            other.size = 0;
            if(data != nullptr) 
                delete[] data;
            data = other.data;
            other.data = nullptr;
        }

        return *this;
    }



    ~Vector() {
        delete[] data;
    }

};


int main() {

    return 0;
}