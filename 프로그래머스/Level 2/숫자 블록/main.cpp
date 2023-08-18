#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void print(vector<int> result);
int max_divisor(int num);
vector<int> solution(long long begin, long long end);

int main(int argc, char* argv[])
{
    print(solution(1, 10));
    print(solution(100'000'014, 100'000'016));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

int max_divisor(int num)
{
    if (num <= 1)
        return 0;

    int last = min(sqrt(num), 10'000'000.0);
    int maxDivisor = 1;

    for (int i = 2; i <= last; ++i)
    {
        if (num % i == 0)
        {
            maxDivisor = max(maxDivisor, i);

            int div2 = num / i;

            if (div2 <= 10'000'000)
                maxDivisor = max(maxDivisor, div2);
        }
    }

    return maxDivisor;
}

vector<int> solution(long long begin, long long end)
{
    size_t n = end - begin + 1;
    vector<int> answer(n);

    for (int i = 0; i < n; ++i)
        answer[i] = max_divisor(begin + i);

    return answer;
}
