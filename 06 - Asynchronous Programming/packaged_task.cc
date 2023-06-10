#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <future>

using namespace std;

double accum(double *beg, double *end, double init)
{
    return accumulate(beg, end, init);
}

int main()
{
    vector<double> v(16);
    iota(v.begin(), v.end(), 1.0);

    auto v0 = &v[0];
    auto sz = v.size();

    using task_type = double(double *, double *, double);
    packaged_task<task_type> pt1{accum};
    packaged_task<task_type> pt2{accum};
    packaged_task<task_type> pt3{accum};
    packaged_task<task_type> pt4{accum};

    auto f1{pt1.get_future()};
    auto f2{pt2.get_future()};
    auto f3{pt3.get_future()};
    auto f4{pt4.get_future()};

    thread t1{move(pt1), v0, v0 + sz / 4, 0};
    thread t2{move(pt2), v0 + sz / 4, v0 + 2 * sz / 4, 0};
    thread t3{move(pt3), v0 + 2 * sz / 4, v0 + 3 * sz / 4, 0};
    thread t4{move(pt4), v0 + 3 * sz / 4, v0 + sz, 0};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout << f1.get() + f2.get() + f3.get() + f4.get();
}