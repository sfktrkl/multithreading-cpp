#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v{3, 1, 4, 1, 5, 9};
    try
    {
        sort(v.begin(), v.end(), [](int a, int b)
             { throw std::out_of_range("Oops"); return true; });
    }
    catch (exception &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
}