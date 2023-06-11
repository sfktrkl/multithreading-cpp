#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "concurrent_queue_cv.h"
#include <functional>
#include <atomic>
#include <thread>

using namespace std;
using Func = std::function<void()>;

class thread_pool
{
    concurrent_queue_cv<Func> work_queue;
    vector<thread> threads;
    void worker()
    {
        while (true)
        {
            Func task;
            work_queue.pop(task);
            task();
        }
    }

public:
    thread_pool()
    {
        const unsigned thread_count = thread::hardware_concurrency();
        for (unsigned i = 0; i < thread_count; ++i)
            threads.push_back(thread{&thread_pool::worker, this});
    }

    ~thread_pool()
    {
        for (auto &t : threads)
        {
            t.join();
        }
    }

    void submit(Func f)
    {
        work_queue.push(f);
    }
};

#endif // THREAD_POOL_H