#include <iostream>
#include <vector>
#include <queue>

#define UNREACHABLE 200'000

using namespace std;

void print(vector<int> result);
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination);

int main(int argc, char* argv[])
{
    print(solution(3, {{1, 2}, {2, 3}}, {2, 3}, 1));
    print(solution(5, {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}}, {1, 3, 5}, 5));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer;
    queue<int> que;
    vector<vector<int>> adj(n + 1);
    vector<int> distance(n + 1, UNREACHABLE);

    for (vector<int>& road : roads)
    {
        adj[road[0]].emplace_back(road[1]);
        adj[road[1]].emplace_back(road[0]);
    }

    distance[destination] = 0;
    que.emplace(destination);

    while (!que.empty())
    {
        int v = que.front(); que.pop();

        for (int vadj : adj[v])
        {
            int dist = distance[v] + 1;

            if (dist < distance[vadj])
            {
                distance[vadj] = dist;
                que.emplace(vadj);
            }
        }
    }

    for (int src : sources)
        if (distance[src] == UNREACHABLE)
            answer.emplace_back(-1);
        else
            answer.emplace_back(distance[src]);

    return answer;
}
