#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int time_to_sec(string time);
int solution(vector<vector<string>> book_time);

int main(int argc, char* argv[])
{
    cout << solution({{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}}) << endl;
    cout << solution({{"09:10", "10:10"}, {"10:20", "12:20"}}) << endl;
    cout << solution({{"10:20", "12:30"}, {"10:20", "12:30"}, {"10:20", "12:30"}}) << endl;

    return 0;
}

int time_to_sec(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

int solution(vector<vector<string>> book_time)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> prQue;

    sort(book_time.begin(), book_time.end());

    for (vector<string>& time : book_time)
    {
        int start = time_to_sec(time[0]);
        int end   = time_to_sec(time[1]) + 10;

        while (!prQue.empty() && prQue.top() <= start)
            prQue.pop();

        prQue.push(end);

        answer = max(answer, int(prQue.size()));
    }

    return answer;
}
