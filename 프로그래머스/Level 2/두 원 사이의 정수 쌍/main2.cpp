#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(int r1, int r2);

int main(int argc, char* argv[])
{
    cout << solution(2, 3) << endl;
    cout << solution(25, 39) << endl;

    return 0;
}

long long solution(int r1, int r2)
{
    long long answer = 0;
    vector<double> memo(r2 + 1);

    for (double n = 0; n <= r2; ++n)
        memo[n] = n * n;

    for (int x = 1; x <= r2; ++x)
    {
        double Y1 = sqrt(max(memo[r1] - memo[x], 0.0));
        double Y2 = sqrt(memo[r2] - memo[x]);

        answer += floor(Y2) - ceil(Y1) + 1;
    }

    return answer * 4;
}
