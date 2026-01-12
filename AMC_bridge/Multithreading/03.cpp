/*
3. What C++ features can we use to protect data between multiple threads?
We use mutex.

*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex carMutex;
mutex bikeMutex;

void driveCar(std::string driverName) {
    unique_lock<mutex> carLock(carMutex);
    cout<<driverName<<" is currently driving the car.\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout<<driverName<<" is done driving the car.\n";
    carLock.unlock();
}

void driveBike(std::string driverName) {
    lock_guard<mutex> bikeLock(bikeMutex);
    cout<<driverName<<" is currently driving the bike.\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout<<driverName<<" is done driving the bike.\n";
}

int main() {

    thread t1(driveCar, "Saldina");
    thread t2(driveCar, "George");

    t1.join();
    t2.join();

    thread t3(driveBike, "Saldina");
    thread t4(driveBike, "George");

    t3.join();
    t4.join();

    return 0;
}