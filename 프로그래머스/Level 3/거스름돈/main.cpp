#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money);

int main(int argc, char* argv[])
{
    cout << solution(5, {1, 2, 5}) << endl;

    return 0;
}

int solution(int n, vector<int> money)
{
    int answer = 0;
    int DIV = 1'000'000'007;
    vector<int> DP(n + 1, 0);

    DP[0] = 1;
    sort(money.begin(), money.end());

    for (int mny : money)
        for (int i = 0; i <= n - mny; ++i)
            DP[i + mny] = (DP[i] + DP[i + mny]) % DIV;

    return DP[n];
}
