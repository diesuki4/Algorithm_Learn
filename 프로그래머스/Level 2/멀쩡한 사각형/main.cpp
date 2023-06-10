#include <iostream>

#define f(x) int(a * (x) + b)

using namespace std;

long long solution(int w, int h);

int main(int argc, char* argv[])
{
    cout << solution(8, 12) << endl;
    cout << solution(2, 2) << endl;

    return 0;
}

long long solution(int w, int h)
{
    long long answer = 0;
    double b = h, a = -(b / w);

    for (int x = 1; x <= w; ++x)
        answer += f(x);

    return answer + answer;
}
