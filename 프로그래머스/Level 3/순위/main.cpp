#include <iostream>
#include <vector>
#include <algorithm>

#define TBD 100

using namespace std;

int solution(int n, vector<vector<int>> results);

int main(int argc, char* argv[])
{
    cout << solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}}) << endl;

    return 0;
}

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, TBD));

    for (vector<int>& r : results)
        graph[r[0]][r[1]] = 1;

    for (int k = 1; k <= n; ++k)
        for (int s = 1; s <= n; ++s)
            for (int e = 1; e <= n; ++e)
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);

    for (int i = 1; i <= n; ++i)
    {
        int nDtrm = 0;

        for (int j = 1; j <= n; ++j)
            nDtrm += (graph[i][j] != TBD) + (graph[j][i] != TBD);

        answer += (nDtrm == (n - 1));
    }

    return answer;
}
