#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int findRep(vector<int>& rep, int i)
{
    if (rep[i] == i)
        return i;
    
    return rep[i] = findRep(rep, rep[i]);
}

bool unionAB(vector<int>& rep, int a, int b)
{
    int repA = findRep(rep, a);
    int repB = findRep(rep, b);

    if (repA == repB)
        return false;

    rep[repA] = rep[repB] = min(repA, repB);

    return true;
}

struct Edge
{
    int s;
    int e;
    int w;

    friend bool operator < (const Edge& A, const Edge& B) { return A.w < B.w; }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<Edge> edges;

    while (E--)
    {
        int s, e, w;
        cin >> s >> e >> w;

        edges.push_back({s, e, w});
    }

    sort(edges.begin(), edges.end());

    int nConnected = 0, answer = 0;
    vector<int> rep(V + 1);

    iota(rep.begin(), rep.end(), 0);

    for (Edge& edge : edges)
    {
        if (unionAB(rep, edge.s, edge.e))
        {
            answer += edge.w;

            if (V - 1 <= ++nConnected)
                break;
        }
    }

    cout << answer;

    return 0;
}
