#include <iostream>
#include <vector>

#define PUDDLE -1

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles);

int main(int argc, char* argv[])
{
    cout << solution(4, 3, {{2, 2}}) << endl;

    return 0;
}

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));

    for (vector<int>& puddle : puddles)
        map[puddle[1]][puddle[0]] = PUDDLE;

    map[0][1] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (map[i][j] == PUDDLE)
                map[i][j] = 0;
            else
                map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1'000'000'007;

    return map[n][m];
}
