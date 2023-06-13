#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print(vector<int> result);
long long factorial(int n);
vector<int> solution(int n, long long k);

int main(int argc, char* argv[])
{
    print(solution(3, 5));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

long long factorial(int n)
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

vector<int> solution(int n, long long k)
{
    vector<int> answer;
    vector<int> numbers(n);

    iota(numbers.begin(), numbers.end(), 1);

    while (0 < n)
    {
        long long fac = factorial(n) / n;
        int idx = (k - 1) / fac;
        idx = (idx < 0) ? 0 : idx;

        k %= fac;
        k = (k) ? k : fac;

        answer.emplace_back(numbers[idx]);
        numbers.erase(numbers.begin() + idx);

        --n;
    }

    return answer;
}
