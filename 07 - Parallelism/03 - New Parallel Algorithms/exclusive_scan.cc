#include <numeric>
#include <iostream>
#include <vector>
#include <execution>

using namespace std;
using namespace std::execution;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v2(v.size());
    exclusive_scan(par_unseq, v.begin(), v.end(), v2.begin(), 1);

    cout << "Original vector elements: ";
    for (auto i : v)
        cout << i << ", ";

    cout << "\nExclusive scan vector elements: ";
    for (auto i : v2)
        cout << i << ", ";
    cout << endl;
}