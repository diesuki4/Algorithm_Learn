#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works);

int main(int argc, char* argv[])
{
    cout << solution(4, {4, 3, 3});
    cout << solution(1, {2, 1, 2});
    cout << solution(3, {1, 1});

    return 0;
}

long long solution(int n, vector<int> works)
{
    long long answer = 0;
    priority_queue<int> prQue;

    for (int w : works)
        prQue.emplace(w);

    while (0 < n)
    {
        int num = prQue.top(); prQue.pop();
        int minus = min(n, num - prQue.top() + 1);

        n -= minus;
        prQue.emplace(max(0, num - minus));
    }

    while (!prQue.empty())
    {
        answer += prQue.top() * prQue.top();
        prQue.pop();
    }

    return answer;
}
