#include <iostream>
#include <deque>
#include <algorithm>
#include <sstream>
#include <string>
#include <cmath>

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
    float last = sqrtf(n);

    for (long i = 2; i <= last; ++i)
        if (n % i == 0)
            return false;

    return n != 1;
}

int solution(int n, int k)
{
    int answer = 0;
    string s = to_base(k, n);
    
    replace(s.begin(), s.end(), '0', ' ');

    istringstream iss(s);

    while (iss >> s)
        answer += is_prime(stol(s));

    return answer;
}
