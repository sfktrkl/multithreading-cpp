// Use std::lock_guard to avoid scrambled output
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>

using namespace std::literals;

std::mutex print_mutex;

void print(std::string str)
{
    for (int i = 0; i < 10; ++i)
    {
        try
        {
            // Create an std::lock_guard object
            // This calls print_mutex.lock()
            std::lock_guard<std::mutex> lck_guard(print_mutex);

            // Start of critical section
            for (int j = 0; j < str.length(); ++j)
                std::cout << str[j];
            std::cout << std::endl;

            // Critical section throws an exception
            throw std::exception();
            // End of critical section
        } // Calls ~std::lock_guard
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