// Uses a wrapper class for std::thread
// Ensures safe destruction when an exception is throw
#include <thread>
#include <iostream>

class ThreadGuard
{
    std::thread thr;

public:
    // Constructor takes rvalue reference argument (std::thread is move-only)
    explicit ThreadGuard(std::thread &&thr) : thr(std::move(thr)) {}

    // Destructor - join the thread if necessary
    ~ThreadGuard()
    {
        if (thr.joinable())
            thr.join();
    }

    ThreadGuard(const ThreadGuard &) = delete; // Deleted copy operators prevent copying
    ThreadGuard &operator=(const ThreadGuard &) = delete;

    // The move assignment operator is not synthesized
};

// Callable object - thread entry point
void hello()
{
    std::cout << "Hello, Thread!\n";
}

int main()
{
    try
    {
        std::thread thr(hello);
        ThreadGuard tguard{std::move(thr)};

        // ThreadGuard tguard{std::thread(hello)};

        // Code which might throw an exception
        throw std::exception();

    } // Calls ~ThreadGuard followed by ~thread
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
}