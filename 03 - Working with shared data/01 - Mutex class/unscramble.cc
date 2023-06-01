// Use a mutex to avoid scrambled output
#include <iostream>
#include <mutex>
#include <thread>
#include <string>

// Global mutex object
std::mutex task_mutex;

void print(std::string str)
{
    for (int i = 0; i < 10; ++i)
    {
        // Lock the mutex before the critical section
        task_mutex.lock();

        // Start of critical section
        for (int j = 0; j < str.length(); ++j)
            std::cout << str[j];
        std::cout << std::endl;
        // End of critical section

        // Unlock the mutex after the critical section
        task_mutex.unlock();
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