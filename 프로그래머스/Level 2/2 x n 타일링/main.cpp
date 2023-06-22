// 이 풀이는 틀린 풀이다.
#include <iostream>
#include <vector>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(4) << endl;

    return 0;
}

int solution(int n)
{
    int answer = 0;
    const int P = 1'000'000'007;
    vector<int> factorials(n + 1, 1);

    for (int i = 2; i <= n; ++i)
        factorials[i] = ((i % P) * factorials[i - 1]) % P;

    for (int i = n, j = 0; i >= j; --i, ++j)
        answer += factorials[i] / factorials[i - j] / factorials[j];

    return answer;
}
