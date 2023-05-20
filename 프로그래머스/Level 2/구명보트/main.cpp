#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit);

int main(int argc, char* argv[])
{
    cout << solution({70, 50, 80, 50}, 100) << endl;
    cout << solution({70, 80, 50}, 100) << endl;
    cout << solution({10, 20, 80, 80}, 100) << endl;

    return 0;
}

int solution(vector<int> people, int limit)
{
    int answer = 0;
    deque<int> deq(people.begin(), people.end());

    sort(deq.begin(), deq.end());

    do
    {
        int total = limit;
        bool bSuccess = false;

        while (!deq.empty() && (deq.back() <= total))
        {
            total -= deq.back();
            deq.pop_back();
            bSuccess = true;
        }

        while (!deq.empty() && (deq.front() <= total))
        {
            total -= deq.front();
            deq.pop_front();
            bSuccess = true;
        }

        answer += bSuccess;
    }
    while (!deq.empty());

    return answer;
}
