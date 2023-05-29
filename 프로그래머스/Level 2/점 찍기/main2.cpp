#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d);

int main(int argc, char* argv[])
{
    cout << solution(2, 4) << endl;
    cout << solution(1, 5) << endl;

    return 0;
}

long long solution(int k, int d)
{
    long long answer = 0;
    double sqrD = pow(d, 2);

    for (int i = 0; i <= d; i += k)
        ++answer += (long long)(sqrt(sqrD - pow(i, 2))) / k;

    return answer;
}
