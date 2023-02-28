#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve);

int main(int argc, char* argv[])
{
    cout << solution(5, {2, 4}, {1, 3, 5}) << endl;
    cout << solution(5, {2, 4}, {3}) << endl;
    cout << solution(3, {3}, {1}) << endl;

    return 0;
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int nLost;
    vector<int> t_lost;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    t_lost = lost;

    for (int l : t_lost)
    {
        auto it = find(reserve.begin(), reserve.end(), l);
        auto jt = find(lost.begin(), lost.end(), l);

        if (it != reserve.end())
        {
            reserve.erase(it);
            lost.erase(jt);
        }
    }

    nLost = lost.size();

    for (int l : lost)
    {
        auto it = find(reserve.begin(), reserve.end(), l - 1);
        auto jt = find(reserve.begin(), reserve.end(), l + 1);

        if (it != reserve.end())
        {
            --nLost;
            reserve.erase(it);
        }
        else if (jt != reserve.end())
        {
            --nLost;
            reserve.erase(jt);
        }
    }

    return n - nLost;
}
