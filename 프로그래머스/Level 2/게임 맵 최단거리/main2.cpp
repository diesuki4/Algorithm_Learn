#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct st;
int solution(vector<vector<int>> maps);

int main(int argc, char* argv[])
{
    cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}) << endl;
    cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}}) << endl;

    return 0;
}

struct st
{
    int i;
    int j;
    int cost;
};

int solution(vector<vector<int>> maps)
{
    queue<st> que;
    que.emplace(st{0, 0, 1});
    int n = maps.size() - 1, m = maps.front().size() - 1;

    while (!que.empty())
    {
        st s = que.front(); que.pop();

        if (s.i < 0 || n < s.i || s.j < 0 || m < s.j || maps[s.i][s.j] == 0)
            continue;
        else if (s.i == n && s.j == m)
            return s.cost;

        maps[s.i][s.j] = 0;

        que.emplace(st{s.i - 1, s.j, s.cost + 1});
        que.emplace(st{s.i + 1, s.j, s.cost + 1});
        que.emplace(st{s.i, s.j - 1, s.cost + 1});
        que.emplace(st{s.i, s.j + 1, s.cost + 1});
    }

    return -1;
}
