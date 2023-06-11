#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> x{1, 2, 3, 4, 5};
    vector<int> y{5, 4, 3, 2, 1};

    auto result = transform_reduce(x.begin(), x.end(), // Iterator range for first vector
                                   y.begin(),          // Start of second vector
                                   0);                 // Initial value of sum

    cout << "First vector:  ";
    for (auto i : x)
        cout << i << ", ";

    cout << endl
         << "Second vector: ";
    for (auto i : y)
        cout << i << ", ";
    cout << endl;

    cout << "Result is " << result << endl; // Displays 35
}