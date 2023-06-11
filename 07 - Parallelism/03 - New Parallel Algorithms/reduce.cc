#include <numeric>
#include <iostream>
#include <vector>
#include <execution>

using namespace std;
using namespace std::execution;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    auto sum = reduce(par_unseq, v.begin(), v.end(), 0);

    cout << "Vector elements: ";
    for (auto i : v)
        cout << i << ", ";
    cout << "\nSum of elements is " << sum << endl;
}