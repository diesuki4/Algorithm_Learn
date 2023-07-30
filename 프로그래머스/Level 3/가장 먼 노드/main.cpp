#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define UNREACHABLE INT_MAX

using namespace std;

int solution(int n, vector<vector<int>> edge);

int main(int argc, char* argv[])
{
    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}}) << endl;

    return 0;
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0, max;
    queue<int> que;
    vector<vector<int>> graph(n + 1);
    vector<int> distance(n + 1, UNREACHABLE);

    for (vector<int>& e : edge)
    {
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
    }

    max = distance[1] = 0;
    que.emplace(1);

    while (!que.empty())
    {
        int v = que.front(); que.pop();

        if (max < distance[v])
        {
            max = distance[v];
            answer = 1;
        }
        else
        {
            ++answer;
        }

        for (int adj : graph[v])
        {
            int dist = distance[v] + 1;

            if (dist < distance[adj])
            {
                distance[adj] = dist;
                que.emplace(adj);
            }
        }
    }

    return answer;
}
