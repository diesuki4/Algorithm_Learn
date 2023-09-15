#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int start;
    int end;
    int time;
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;
        vector<int> cost(N + 1, 0);

        for (int i = 0; i < M; ++i)
        {
            int start, end, time;
            cin >> start >> end >> time;

            edges.push_back({start, end, time});
            edges.push_back({end, start, time});
        }

        for (int i = 0; i < W; ++i)
        {
            int start, end, time;
            cin >> start >> end >> time;

            edges.push_back({start, end, -time});
        }

        while (--N)
        {
            for (Edge& edge : edges)
            {
                int cst = cost[edge.start] + edge.time;

                if (cst < cost[edge.end])
                    cost[edge.end] = cst;
            }
        }

        bool bNegativeCycle = false;

        for (Edge& edge : edges)
        {
            int cst = cost[edge.start] + edge.time;

            if (cst < cost[edge.end])
            {
                bNegativeCycle = true;
                break;
            }
        }

        cout << (bNegativeCycle ? "YES\n" : "NO\n");
    }

    return 0;
}
