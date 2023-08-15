#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy);

int main(int argc, char* argv[])
{
    cout << solution(7, 3, {4, 2, 4, 5, 3, 3, 1}) << endl;
    cout << solution(2, 4, {3, 3, 3, 3}) << endl;

    return 0;
}

int solution(int n, int k, vector<int> enemy)
{
    int ans;
    priority_queue<int, vector<int>, greater<int>> prQue;

    for (ans = 0; ans < enemy.size(); ++ans)
    {
        if (0 < k)
        {
            --k;
            prQue.emplace(enemy[ans]);
        }
        else if (!prQue.empty() && prQue.top() < enemy[ans])
        {
            n -= prQue.top();
            prQue.pop();
            prQue.emplace(enemy[ans]);
        }
        else
        {
            n -= enemy[ans];
        }

        if (n < 0)
            return ans;
    }

    return ans;
}
