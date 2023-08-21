#include <iostream>

using namespace std;

int f(int n, long long x);
int solution(int n, long long l, long long r);

int main(int argc, char* argv[])
{
    cout << solution(2, 4, 17) << endl;

    return 0;
}

int f(int n, long long x)
{
    if (n == 1 || f(n - 1, x / 5))
        return (x % 5) != 2;
    else
        return 0;
}

int solution(int n, long long l, long long r)
{
    int answer = 0;

    for (long long i = l - 1; i < r; ++i)
        answer += f(n, i);

    return answer;
}
