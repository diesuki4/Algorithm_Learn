#include <iostream>
#include <vector>
#include <algorithm>

#define UNREACHABLE 19'900'000

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares);

int main(int argc, char* argv[])
{
    cout << solution(6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) << endl;
    cout << solution(7, 3, 4, 1, {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}) << endl;
    cout << solution(6, 4, 5, 6, {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}}) << endl;

    return 0;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = UNREACHABLE;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, UNREACHABLE));

    for (int i = 1; i <= n; ++i)  graph[i][i] = 0;
    for (vector<int>& fr : fares) graph[fr[0]][fr[1]] = graph[fr[1]][fr[0]] = fr[2];

    for (int K = 1; K <= n; ++K)
        for (int S = 1; S <= n; ++S)
            for (int E = 1; E <= n; ++E)
                graph[S][E] = min(graph[S][E], graph[S][K] + graph[K][E]);

    for (int i = 1; i <= n; ++i)
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);

    return answer;
}
