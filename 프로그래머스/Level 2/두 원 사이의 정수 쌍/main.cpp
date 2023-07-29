// 이 풀이는 틀린 풀이다.
#include <iostream>
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

    for (double x = 1; x <= r2; ++x)
    {
        double theta1 = acos(min(x / r1, 1.0));
        double theta2 = acos(x / r2);

        double Y1 = r1 * sin(theta1);
        double Y2 = r2 * sin(theta2);

        answer += floor(Y2) - ceil(Y1) + 1;
    }

    return answer * 4;
}
