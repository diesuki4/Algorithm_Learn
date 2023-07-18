// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point;
int solution(int m, int n, vector<vector<int>> puddles);

int main(int argc, char* argv[])
{
    cout << solution(4, 3, {{2, 2}}) << endl;

    return 0;
}

struct point
{
    int dist;
    int x;
    int y;
};

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    int minDist = 0;
    int dx[] = {1, 0}, dy[] = {0, 1};
    
    queue<point> que;
    vector<vector<bool>> map(n, vector<bool>(m, true));

    for (vector<int>& puddle : puddles)
        map[puddle[1] - 1][puddle[0] - 1] = false;

    --m, --n;
    que.emplace(point{0, 0, 0});

    while (!que.empty())
    {
        point p = que.front();
        que.pop();

        if (0 < minDist && minDist < p.dist)
            break;

        if (p.x == m && p.y == n && minDist == 0)
            minDist = p.dist;

        if (p.x == m && p.y == n && p.dist == minDist)
            ++answer;

        for (int i = 0; i < 2; ++i)
        {
            int x = p.x + dx[i];
            int y = p.y + dy[i];

            if (x <= m && y <= n && map[y][x])
                que.emplace(point{p.dist + 1, x, y});
        }
    }

    return answer;
}
