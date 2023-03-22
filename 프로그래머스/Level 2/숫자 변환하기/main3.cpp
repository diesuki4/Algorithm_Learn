#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int solution(int x, int y, int n);

int main(int argc, char* argv[])
{
    cout << solution(10, 40, 5) << endl;
    cout << solution(10, 40, 30) << endl;
    cout << solution(2, 5, 4) << endl;

    return 0;
}

int solution(int x, int y, int n)
{
    queue<pair<int, int>> que;

    que.emplace(make_pair(y, 0));

    while (!que.empty())
    {
        int val = que.front().first;
        int count = que.front().second;
        que.pop();

        if (val == x)
            return count;
        else if (val < x)
            continue;

        if (~val & 1)
            que.emplace(make_pair(val / 2, count + 1));
        if (val % 3 == 0)
            que.emplace(make_pair(val / 3, count + 1));
        if (n < val)
            que.emplace(make_pair(val - n, count + 1));
    }

    return -1;
}
