// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int solution(int x, int y, int n);

int main(int argc, char* argv[])
{
    cout << solution(10, 40, 5) << endl;
    cout << solution(10, 40, 30) << endl;
    cout << solution(2, 5, 4) << endl;

    return 0;
}

int solution(int x, int y, int n)
{
    auto op1 = [n](int x) { return x + n; };
    auto op2 = [ ](int x) { return x + x; };
    auto op3 = [ ](int x) { return x + x + x; };
    queue<pair<int, int>> que;

    que.emplace(make_pair(0, x));

    while (!que.empty())
    {
        auto& pr = que.front(); que.pop();

        if (pr.second == y)
            return pr.first;
        else if (y < pr.second)
            continue;

        que.emplace(make_pair(pr.first + 1, op1(pr.second)));
        que.emplace(make_pair(pr.first + 1, op2(pr.second)));
        que.emplace(make_pair(pr.first + 1, op3(pr.second)));
    }

    return -1;
}
