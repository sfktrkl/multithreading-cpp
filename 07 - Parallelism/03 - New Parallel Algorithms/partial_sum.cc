#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v2(v.size());
    partial_sum(v.begin(), v.end(), v2.begin());

    cout << "Original vector elements: ";
    for (auto i : v)
        cout << i << ", ";

    cout << "\nPartial sum vector elements: ";
    for (auto i : v2)
        cout << i << ", ";
    cout << endl;
}