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

    auto f1 = async(accum, v0, v0 + sz / 4, 0.0);
    auto f2 = async(accum, v0 + sz / 4, v0 + 2 * sz / 4, 0.0);
    auto f3 = async(accum, v0 + 2 * sz / 4, v0 + 3 * sz / 4, 0.0);
    auto f4 = async(accum, v0 + 3 * sz / 4, v0 + sz, 0.0);
    cout << f1.get() + f2.get() + f3.get() + f4.get();
}
