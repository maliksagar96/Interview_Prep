/*
    4. How can we synchronize data between threads?
    Ans . 1) We can use mutex. 
            2) We can use atomics.
            3) We can use conditional variables.
            4) 
*/

#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>

using namespace std;

int main() {

    atomic<int> counter = 0;

    auto work = [&counter](){
        for(int i = 0;i<100000;i++) {
            counter += 1;
        }
    };

    std::thread t1(work);
    std::thread t2(work);

    t1.join();
    t2.join();

    cout<<"Counter = "<<counter<<endl;

    return 0;
}