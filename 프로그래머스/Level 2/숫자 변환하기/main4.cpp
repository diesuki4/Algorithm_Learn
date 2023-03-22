#include <iostream>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n);

int main(int argc, char* argv[])
{
    cout << solution(10, 40, 5) << endl;
    cout << solution(10, 40, 30) << endl;
    cout << solution(2, 5, 4) << endl;

    return 0;
}

int solution(int x, int y, int n)
{
    int answer;
    int* dp = new int[1'000'001];

    fill(dp, dp + 1'000'001, 10'000'000);
    dp[x] = 0;

    for (int i = x; i <= y; ++i)
    {
        if (i + n <= y)
            dp[i + n] = min(dp[i + n], dp[i] + 1);
        if (i * 2 <= y)
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if (i * 3 <= y)
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }

    answer = (dp[y] == 10'000'000) ? -1 : dp[y];

    delete[] dp;
    dp = nullptr;

    return answer;
}
