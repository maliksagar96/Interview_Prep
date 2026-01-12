/*

When is thread not joinable?
Ans - 1) When it has been either joined already.
        2) if it is moved, std::thread t2 = std::move(t1), t1 is now empty
        3) There was default constructor, std::thread t.

*/

#include <iostream>
#include <thread>

using namespace std;

void hello() {
    cout<<"Hello from thread.\n";
}

int main() {

    std::thread t1(hello);

    t1.join();

    cout<<"Back in main.\n";

    return 0;
}

