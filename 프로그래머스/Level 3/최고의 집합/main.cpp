// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void print(vector<int> result);
deque<deque<int>> get_sum_sets(int num, int n, int sum);
vector<int> solution(int n, int s);

int main(int argc, char* argv[])
{
    print(solution(2, 9));
    print(solution(2, 1));
    print(solution(2, 8));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

deque<deque<int>> get_sum_sets(int num, int n, int sum)
{
    if (n == 1 && num <= sum)
        return {{sum}};

    deque<deque<int>> result;

    for (int i = num; i <= sum - n + 1; ++i)
    {
        for (deque<int>& deq : get_sum_sets(i, n - 1, sum - i))
        {
            deq.emplace_front(i);

            result.emplace_back(deq);
        }
    }

    return result;
}

vector<int> solution(int n, int s)
{
    int max = -1;
    vector<int> answer {-1};

    for (deque<int>& deq : get_sum_sets(1, n, s))
    {
        int mul = 1;

        for (int e : deq)
            mul *= e;

        if (max <= mul)
            answer = vector<int>(deq.begin(), deq.end());
    }

    return answer;
}
