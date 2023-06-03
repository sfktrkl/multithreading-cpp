// Use std::lock_guard to avoid scrambled output
// Find out what happens when an exception is thrown
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>

using namespace std::literals;

std::mutex task_mutex; // Global mutex object

void print(const std::string &str)
{
    for (int i = 0; i < 10; ++i)
    {
        try
        {
            // Lock the mutex before the critical section
            task_mutex.lock();

            // Start of critical section
            for (int j = 0; j < str.length(); ++j)
                std::cout << str[j];
            std::cout << std::endl;

            // Critical section throws an exception
            throw std::exception();
            // End of critical section

            // Never gets called
            task_mutex.unlock();
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << '\n';
        }
    }
}

int main()
{
    std::thread thr1(print, "qwertyu");
    std::thread thr2(print, "asdfghj");
    std::thread thr3(print, "zxcvbnm");

    thr1.join();
    thr2.join();
    thr3.join();
}