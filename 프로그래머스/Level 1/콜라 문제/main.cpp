#include <iostream>

using namespace std;

int solution(int a, int b, int n);

int main(int argc, char* argv[])
{
    cout << solution(2, 1, 20) << endl;
    cout << solution(3, 1, 20) << endl;

    return 0;
}

int solution(int a, int b, int n)
{
    int answer = 0;

    while (a <= n)
    {
        int t = n % a;

        answer += (n = n / a * b);

        n += t;
    }

    return answer;
}
