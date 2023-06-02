#include <iostream>
#include <deque>

using namespace std;

string to_base(int n, int num);
string solution(int n, int t, int m, int p);

int main(int argc, char* argv[])
{
    cout << solution(2, 4, 2, 1) << endl;
    cout << solution(16, 16, 2, 1) << endl;
    cout << solution(16, 16, 2, 2) << endl;

    return 0;
}

string to_base(int n, int num)
{
    deque<char> deq;

    const char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                            'A', 'B', 'C', 'D', 'E', 'F'};

    do
        deq.emplace_front(numbers[num % n]);
    while (num /= n);

    return string(deq.begin(), deq.end());
}

string solution(int n, int t, int m, int p)
{
    string answer, temp;

    for (int num = 0; temp.size() <= t * m; ++num)
        temp += to_base(n, num);

    for (int i = 0; i < t; ++i)
        answer += temp[(m * i) + (p - 1)];

    return answer;
}
