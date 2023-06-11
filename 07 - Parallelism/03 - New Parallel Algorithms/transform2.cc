#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4};
    vector<int> v2{5, 6, 7, 8};
    vector<int> v3;

    // Add each element in v to the corresponding element in v2 and store the result in v3
    transform(v.begin(), v.end(), v2.begin(), back_inserter(v3),
              [](int n1, int n2)
              { return n1 + n2; });

    cout << "First input vector:  ";
    for (auto i : v)
        cout << i << ", ";
    cout << endl;

    cout << "Second input vector: ";
    for (auto i : v2)
        cout << i << ", ";
    cout << endl;

    cout << "Output vector: ";
    for (auto i : v3)
        cout << i << ", ";
    cout << endl;
}