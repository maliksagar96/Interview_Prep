/*
    2. What two modes of execution of the thread function can you name?
    Ans - Synchronous and Asynchronous.

    The following an asynchronous thread example. The aysnchronous thread is a fire and forget mechanism. 
    The asynchronous thread is at the mercy of the main program. 
    It doesn't guarantee anything. 
    It doesn't guarantee complete execution, it doesn't guarantee error handling. 
    It's just a tool, if one feels one need to use it, they can.

*/

// async_log.cpp
#include <iostream>
#include <thread>
#include <fstream>
#include <chrono>
#include <ctime>

void log_message(const std::string& msg) {
    // Simulate slow I/O (e.g., writing to disk or network)
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::ofstream log("app.log", std::ios::app);
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    log << "[" << std::ctime(&now) << "] " << msg << "\n";
    // File closes automatically
}

int main() {
    std::cout << "Starting important work...\n";

    // Fire off logging asynchronously — don't wait!
    std::thread logger(log_message, "User performed critical action");
    logger.detach();  // ← asynchronous execution

    std::cout << "Important work done immediately!\n";

    // Main continues instantly; logging happens in background
    // (Note: if program exits too soon, log might not finish!)
    std::this_thread::sleep_for(std::chrono::seconds(3)); // keep alive so log completes

    return 0;
}


