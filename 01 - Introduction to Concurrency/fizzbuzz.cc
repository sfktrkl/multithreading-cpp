#include <iostream>
#include <thread>
#include <string>

using namespace std;

void speak()
{
    const auto nplayers{4};
    const auto max_number{30};
    string player_names[]{"Abdul", "Bart", "Claudia", "Divya"};
    for (auto i = 1; i <= max_number; ++i)
    {
        auto player = player_names[(i - 1) % nplayers];
        cout << player << " says ";
        if (i % 3 == 0 && i % 5 == 0)
            cout << "fizzbuzz!";
        else if (i % 3 == 0)
            cout << "fizz!";
        else if (i % 5 == 0)
            cout << "buzz!";
        else
            cout << i;
        cout << endl;
    }
}

int main()
{
    thread game{speak};
    game.join();
}