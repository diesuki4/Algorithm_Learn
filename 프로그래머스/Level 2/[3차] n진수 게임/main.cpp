#include <iostream>
#include <deque>

using namespace std;

deque<char> to_base(int n, int num);
string solution(int n, int t, int m, int p);

int main(int argc, char* argv[])
{
    cout << solution(2, 4, 2, 1) << endl;
    cout << solution(16, 16, 2, 1) << endl;
    cout << solution(16, 16, 2, 2) << endl;

    return 0;
}

deque<char> to_base(int n, int num)
{
    deque<char> deq;

    const char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                            'A', 'B', 'C', 'D', 'E', 'F'};

    do
        deq.emplace_front(numbers[num % n]);
    while (num /= n);

    return deq;
}

string solution(int n, int t, int m, int p)
{
    int num = 0, cur = 0;
    string answer;
    deque<char> deq;
    
    p %= m;

    while (t)
    {
        if (deq.empty())
            deq = to_base(n, num++);

        if ((++cur % m) == p)
        {
            answer += deq.front();

            --t;
        }

        deq.pop_front();
    }

    return answer;
}
