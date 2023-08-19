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
    int d = 0, p = 0;

    for (int i = n - 1; 0 <= i; --i)
    {
        if (0 < deliveries[i] || 0 < pickups[i])
        {
            int cnt = 0;

            while (d < deliveries[i] || p < pickups[i])
            {
                ++cnt;
                d += cap;
                p += cap;
            }

            d -= deliveries[i];
            p -= pickups[i];
            answer += (i + 1) * cnt * 2;
        }
    }

    return answer;
}
