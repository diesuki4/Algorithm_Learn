#include <iostream>
#include <vector>
#include <climits>

#define UNREACHABLE LLONG_MAX

using namespace std;

struct Edge
{
    int s;
    int e;
    int w;
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;

    while (M--)
    {
        int start, end, time;
        cin >> start >> end >> time;

        edges.push_back({start, end, time});
    }

    vector<long long> cost(N + 1, UNREACHABLE);
    cost[1] = 0;

    while (--N)
    {
        for (Edge& ed : edges)
        {
            long long c = cost[ed.s] + ed.w;

            if (cost[ed.s] != UNREACHABLE && c < cost[ed.e])
                cost[ed.e] = c;
        }
    }

    for (Edge& ed : edges)
    {
        long long c = cost[ed.s] + ed.w;

        if (cost[ed.s] != UNREACHABLE && c < cost[ed.e])
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = 2; i < cost.size(); ++i)
        cout << (cost[i] == UNREACHABLE ? -1 : cost[i]) << endl;

    return 0;
}
