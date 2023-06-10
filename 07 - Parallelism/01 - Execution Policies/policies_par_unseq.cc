#include <algorithm>
#include <vector>
#include <iostream>
#include <execution>
#include <atomic>

using namespace std;
using namespace std::execution;

int main()
{
    vector<int> v(2000);
    atomic<int> count{0};
    for_each(par_unseq, v.begin(), v.end(), [&](int &x)
             { x = ++count; });

    for (auto i : v)
        cout << i << ", ";
}