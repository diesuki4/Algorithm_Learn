#include <iostream>
#include <vector>
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
    int l = 0, r = people.size() - 1;

    sort(people.begin(), people.end());

    do
    {
        int total = limit;

        while ((l <= r) && (people[r] <= total))
            total -= people[r--];

        while ((l <= r) && (people[l] <= total))
            total -= people[l++];

        answer += (total != limit);
    }
    while (l <= r);

    return answer;
}
