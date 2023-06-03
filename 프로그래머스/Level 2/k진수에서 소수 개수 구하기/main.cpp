// 이 풀이는 메모리 초과가 발생한다.
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

string to_base(int n, int num);
bool is_prime(long n);
int solution(int n, int k);

int main(int argc, char* argv[])
{
    cout << solution(437674, 3) << endl;
    cout << solution(110011, 10) << endl;

    return 0;
}

string to_base(int n, int num)
{
    deque<char> deq;
    const char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    do
        deq.emplace_front(numbers[num % n]);
    while (num /= n);

    return string(deq.begin(), deq.end());
}

bool is_prime(long n)
{
    long last = n / 2;
    static vector<bool> v(n + 1, true);

    if (v[1] == false)
        return v[n];

    v[1] = false;

    for (long i = 2; i <= last; ++i)
        if (v[i])
            for (long j = 2 * i; j <= n; j += i)
                v[j] = false;

    return v[n];
}

int solution(int n, int k)
{
    int answer = 0;
    string s = to_base(k, n);
    
    replace(s.begin(), s.end(), '0', ' ');

    istringstream iss(s);
    vector<long> primes;
    long Max = -1;

    while (iss >> s)
    {
        long num = stol(s);

        Max = max(num, Max);
        primes.emplace_back(num);
    }

    is_prime(Max);

    for (long num : primes)
        answer += is_prime(num);

    return answer;
}
