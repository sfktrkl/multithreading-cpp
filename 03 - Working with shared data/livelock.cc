#include <iostream>
#include <thread>
#include <mutex>

int x{0};
std::mutex m;

void func()
{
    // Thread 1 tests x == 0. This is true because x has not been modified
    // Thread 2 tests x == 0. This is true because x has not been modified
    // Thread 1 sets x to 1 - x. Now x is equal to 1
    // Thread 2 sets x to 1 - x. Now x is equal to 0 again
    // Thread 1 tests x == 0. This is true
    // Thread 2 tests x == 0. This is true
    // Thread 1 sets x to 1 - x. Now x is equal to 1
    // Thread 2 sets x to 1  x. Now x is equal to 0 again
    // ...
    std::lock_guard<std::mutex> lg(m);
    while (x == 0)
    {
        x = 1 - x;
    }
}

int main()
{
    std::thread thr1{func};
    std::thread thr2{func};

    thr1.join();
    thr2.join();
}
