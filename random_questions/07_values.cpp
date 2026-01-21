#include <iostream>
#include <utility>

using namespace std;

void printInt(int a) {
    cout << "[by const lvalue ref] Value = " << a << endl;
} 

void printInt(int &a) {
    cout << "[by non-const lvalue ref] Value = " << a << endl;
} 

int main() {
    int a = 10;
    printInt(a);  
  
    return 0;
}