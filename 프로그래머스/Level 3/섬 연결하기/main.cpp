#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int findRep(vector<int>& rep, int i);
bool unionAB(vector<int>& rep, int a, int b);
int solution(int n, vector<vector<int>> costs);

int main(int argc, char* argv[])
{
    cout << solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}}) << endl;

    return 0;
}

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

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    int nConnected = 0;
    vector<int> rep(n);

    iota(rep.begin(), rep.end(), 0);
    sort(costs.begin(), costs.end(), [](auto& e1, auto& e2) { return e1[2] < e2[2]; });

    for (vector<int>& e : costs)
    {
        if (unionAB(rep, e[0], e[1]))
        {
            answer += e[2];

            if (n - 1 <= ++nConnected)
                break;
        }
    }

    return answer;
}
