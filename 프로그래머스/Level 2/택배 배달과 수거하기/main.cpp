#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups);

int main(int argc, char* argv[])
{
    cout << solution(4,	5, {1, 0, 3, 1, 2}, {0, 3, 0, 4, 0}) << endl;
    cout << solution(2,	7, {1, 0, 2, 0, 1, 0, 2}, {0, 2, 0, 1, 0, 2, 0}) << endl;

    return 0;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int ed = n - (find_if(deliveries.rbegin(), deliveries.rend(), [](int num) { return num != 0; }) - deliveries.rbegin()) - 1;
    int ep = n - (find_if(pickups.rbegin(), pickups.rend(), [](int num) { return num != 0; }) - pickups.rbegin()) - 1;

    while (0 <= ed || 0 <= ep)
    {
        int e = max(ed, ep);
        answer += (1 + e + e + 1);

        int d = cap;

        for (int i = ed; 0 <= i; --i)
        {
            if (deliveries[i] < d)
                d -= deliveries[i],
                deliveries[i] = 0;
            else
                deliveries[i] -= d,
                d = 0;

            ed -= (deliveries[i] == 0);

            if (d < deliveries[i])
                break;
        }

        int p = cap;

        for (int i = ep; 0 <= i; --i)
        {
            if (pickups[i] < p)
                p -= pickups[i],
                pickups[i] = 0;
            else
                pickups[i] -= p,
                p = 0;

            ep -= (pickups[i] == 0);

            if (p < pickups[i])
                break;
        }
    }

    return answer;
}
