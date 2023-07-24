#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point;
struct Entity;
int distance(vector<string>& maps, Point from, Point to);
int solution(vector<string> maps);

int main(int argc, char* argv[])
{
    cout << solution({"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"}) << endl;
    cout << solution({"LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"}) << endl;

    return 0;
}

struct Point
{
    unsigned x;
    unsigned y;

    bool operator == (const Point& p) { return (x == p.x) && (y == p.y); }
};

struct Entity
{
    int level;
    Point point;
};

int distance(vector<string>& maps, Point from, Point to)
{
    int X = maps.size(), Y = maps.front().length();
    static const int dx[] = {1, -1, 0, 0};
    static const int dy[] = {0, 0, 1, -1};

    queue<Entity> que;
    vector<vector<bool>> visited(X, vector<bool>(Y, false));

    que.emplace(Entity {0, from});

    while (!que.empty())
    {
        Entity e = que.front(); que.pop();

        if (e.point == to)
            return e.level;
        else if (X <= e.point.x || Y <= e.point.y)
            continue;
        else if (maps[e.point.x][e.point.y] == 'X')
            continue;
        else if (visited[e.point.x][e.point.y])
            continue;

        visited[e.point.x][e.point.y] = true;

        for (int i = 0; i < 4; ++i)
            que.emplace(Entity {e.level + 1, {e.point.x + dx[i], e.point.y + dy[i]}});
    }

    return -1;
}

int solution(vector<string> maps)
{
    int answer;
    int X = maps.size(), Y = maps.front().length();

    Point S, L, E;

    for (unsigned x = 0; x < X; ++x)
        for (unsigned y = 0; y < Y; ++y)
            if (maps[x][y] == 'S')
                S = {x, y};
            else if (maps[x][y] == 'L')
                L = {x, y};
            else if (maps[x][y] == 'E')
                E = {x, y};

    int dist = distance(maps, S, L);
    if (dist == -1) return -1;
    else            answer = dist;

    dist = distance(maps, L, E);
    if (dist == -1) return -1;
    else            answer += dist;

    return answer;
}
