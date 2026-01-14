/*
25. What are conditional variables?

Ans . Conditional variables (or condition variables) are synchronization primitives that allow threads to 
      wait until a specific condition becomes true.  

      Features
      wait()
      notify_one()
      notify_all()
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::queue<int> data_queue;
std::mutex mtx;
std::condition_variable cv;
bool finished = false;

// Producer thread: adds items to the queue
void producer() {
    for (int i = 1; i <= 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate work
        std::lock_guard<std::mutex> lock(mtx);
        data_queue.push(i);
        std::cout << "Produced: " << i << '\n';
        cv.notify_one(); // Wake up one waiting consumer
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        finished = true; // Signal that production is done
    }
    cv.notify_all(); // Ensure consumer wakes up to see 'finished'
}

// Consumer thread: processes items from the queue
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until either there's data or production is finished
        cv.wait(lock, []{ return !data_queue.empty() || finished; });

        if (!data_queue.empty()) {
            int value = data_queue.front();
            data_queue.pop();
            lock.unlock(); // Release lock before processing
            std::cout << "Consumed: " << value << '\n';
        } else if (finished) {
            break; // No more data will arrive
        }
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    std::cout << "Done.\n";
    return 0;
}