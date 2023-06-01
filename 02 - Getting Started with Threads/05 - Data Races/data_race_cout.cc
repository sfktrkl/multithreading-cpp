// Unsynchronized threads which make conflicting accesses.
// But where is the shared memory location?
#include <thread>
#include <iostream>

void print(std::string str)
{
    // A very artificial way to display a string!
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < str.length(); ++j)
            std::cout << str[j];
        std::cout << std::endl;
    }
}

int main()
{
    std::thread thr1(print, "qwertyu");
    std::thread thr2(print, "asdfghj");
    std::thread thr3(print, "zxcvbnm");

    // Wait for the tasks to complete
    thr1.join();
    thr2.join();
    thr3.join();
}