#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location);

int main(int argc, char* argv[])
{
    cout << solution({2, 1, 3, 2}, 2) << endl;
    cout << solution({1, 1, 9, 1, 1, 1}, 0) << endl;

    return 0;
}

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    int loc_printed = -1;
    deque<int> deq(priorities.begin(), priorities.end());
    deque<int> locations(priorities.size());

    iota(locations.begin(), locations.end(), 0);
    sort(priorities.begin(), priorities.end());

    while (loc_printed != location)
    {
        if (deq.front() != priorities.back())
        {
            deq.emplace_back(deq.front());
            deq.pop_front();

            loc_printed = -1;
            locations.emplace_back(locations.front());
            locations.pop_front();
        }
        else
        {
            deq.pop_front();

            loc_printed = locations.front();
            locations.pop_front();

            priorities.pop_back();

            ++answer;
        }
    }

    return answer;
}
