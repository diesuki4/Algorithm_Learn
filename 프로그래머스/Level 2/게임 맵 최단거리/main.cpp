// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

enum class DIR;
void rDFS(vector<vector<int>>& maps, int i, int j, int from, int cost);
int solution(vector<vector<int>> maps);

int main(int argc, char* argv[])
{
    cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}) << endl;
    cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}}) << endl;

    return 0;
}

enum class DIR
{
    Up    = 1,
    Down  = 2,
    Left  = 4,
    Right = 8
};

void rDFS(vector<vector<int>>& maps, int i, int j, int from, int cost)
{
    int n = maps.size(), m = maps.front().size();

    if (i < 0 || n <= i || j < 0 || m <= j || maps[i][j] == 0 || maps[i][j] <= cost)
        return;

    maps[i][j] = cost;

    if (int(DIR::Up) & ~from) rDFS(maps, i - 1, j, int(DIR::Down), cost + 1);
    if (int(DIR::Down) & ~from) rDFS(maps, i + 1, j, int(DIR::Up), cost + 1);
    if (int(DIR::Left) & ~from) rDFS(maps, i, j - 1, int(DIR::Right), cost + 1);
    if (int(DIR::Right) & ~from) rDFS(maps, i, j + 1, int(DIR::Left), cost + 1);
}

int solution(vector<vector<int>> maps)
{
    for_each(maps.begin(), maps.end(), [](vector<int>& v) { replace(v.begin(), v.end(), 1, INT_MAX); });

    rDFS(maps, 0, 0, int(DIR::Up) | int(DIR::Left), 1);

    return (maps.back().back() == INT_MAX) ? -1 : maps.back().back();
}
