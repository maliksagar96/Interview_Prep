/*

20. What is specialization? How can it help to improve efficiency?  

 If the function process is called with any other datatype then the process which is defined with the generic code will be called.
 If the function process with int is called then the specific function will be called. 
*/

#include <iostream>

using namespace std;
// Generic version
template<typename T>
void process(T x) {
    // generic, maybe slow
}

// Specialized for int
template<>
void process<int>(int x) {
    // highly optimized integer-specific code
}