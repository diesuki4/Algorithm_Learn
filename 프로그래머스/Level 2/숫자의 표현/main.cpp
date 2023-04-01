// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(15) << endl;

    return 0;
}

int solution(int n)
{
    int answer = 0;
    vector<int> sum(n + 1, 0);

    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + i;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < n; ++j)
            if (sum[i] - sum[j] == n)
                ++answer;

    return answer;
}
