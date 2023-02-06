#include <iostream>
#include <vector>

using namespace std;
using ullong = unsigned long long;

ullong solution(int balls, int share);

int main(int argc, char* argv[])
{
    cout << solution(3, 2) << endl;
    cout << solution(5, 3) << endl;

    return 0;
}

ullong solution(int balls, int share)
{
    vector<vector<ullong>> table(balls + 1);

    for (int i = 1; i <= balls; ++i)
    {
        table[i].push_back(1);

        for (int j = 1; j < i; ++j)
            table[i].push_back(table[i - 1][j - 1] + table[i - 1][j]);

        table[i].push_back(1);
    }

    return table[balls][share];
}
