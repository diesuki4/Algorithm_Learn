#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping);

int main(int argc, char* argv[])
{
    cout << solution({1, 2, 1, 3, 1, 4, 1, 2}) << endl;
    cout << solution({1, 2, 3, 1, 4}) << endl;

    return 0;
}

int solution(vector<int> topping)
{
    int answer = 0;
    unordered_map<int, int> umapA, umapB;

    for (int tp : topping)
        ++umapB[tp];

    for (int tp : topping)
    {
        ++umapA[tp];

        if (--umapB[tp] <= 0)
            umapB.erase(tp);

        if (umapA.size() == umapB.size())
            ++answer;
    }

    return answer;
}
