#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2);

int main(int argc, char* argv[])
{
    cout << solution({3, 2, 7, 2}, {4, 6, 5, 1}) << endl;
    cout << solution({1, 2, 1, 2}, {1, 10, 1, 2}) << endl;
    cout << solution({1, 1}, {1, 5}) << endl;

    return 0;
}

int solution(vector<int> queue1, vector<int> queue2)
{
    deque<int> deque1(queue1.begin(), queue1.end());
    deque<int> deque2(queue2.begin(), queue2.end());

    int cnt1 = 0, cnt2 = 0;
    int n1 = deque1.size() * 2, n2 = deque2.size() * 2;
    int diff = accumulate(deque1.begin(), deque1.end(), 0) - accumulate(deque2.begin(), deque2.end(), 0);

    if (diff & 1)
        return -1;

    while (diff && cnt1 <= n1 && cnt2 <= n2)
    {
        if (0 < diff)
        {
            deque2.emplace_back(deque1.front());
            deque1.pop_front();
            diff -= (deque2.back() * 2);
            ++cnt1;
        }
        else
        {
            deque1.emplace_back(deque2.front());
            deque2.pop_front();
            diff += (deque1.back() * 2);
            ++cnt2;
        }
    }

    return (diff == 0) ? (cnt1 + cnt2) : -1;
}
