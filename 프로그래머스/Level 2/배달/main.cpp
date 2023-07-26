#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define UNREACHABLE INT_MAX

using namespace std;

struct Edge;
void Dijkstra(vector<vector<Edge>>& dist, vector<int>& cost);
int solution(int N, vector<vector<int> > road, int K);

int main(int argc, char* argv[])
{
    cout << solution(5, {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}}, 3) << endl;
    cout << solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4) << endl;

    return 0;
}

typedef struct Edge
{
    union { int to;     int v; };
    union { int dist;   int cost; };

    friend bool operator < (const Info& A, const Info& B) { return A.cost < B.cost; }
} Info;

void Dijkstra(vector<vector<Edge>>& dist, vector<int>& cost)
{
    queue<Info> que;

    que.emplace(Info {1, 0});
    cost[1] = 0;

    while (!que.empty())
    {
        Info i = que.top(); que.pop();

        for (Edge& adj : dist[i.v])
        {
            if (cost[adj.to] > i.cost + adj.dist)
            {
                cost[adj.to] = i.cost + adj.dist;
                que.emplace(Edge {adj.to , cost[adj.to]});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 1;
    vector<vector<Edge>> dist(N + 1);
    vector<int> cost(N + 1, UNREACHABLE);

    for (vector<int>& rd : road)
    {
        dist[rd[0]].emplace_back(Edge {rd[1], rd[2]});
        dist[rd[1]].emplace_back(Edge {rd[0], rd[2]});
    }

    Dijkstra(dist, cost);

    for (int i = 2; i <= N; ++i)
        answer += (cost[i] <= K);

    return answer;
}
