#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Section;
int solution(vector<vector<int>> targets);

int main(int argc, char* argv[])
{
    cout << solution({{4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4}}) << endl;

    return 0;
}

struct Section
{
    int start;
    int end;

    friend bool operator < (const Section& A, const Section& B) { return A.start > B.start; }
};

int solution(vector<vector<int>> targets)
{
    int answer = 0;
    int end = -1;
    priority_queue<Section> prQue;

    for (vector<int>& t : targets)
        prQue.push({t[0], t[1]});

    while (!prQue.empty())
    {
        Section sec = prQue.top(); prQue.pop();

        if (end <= sec.start)
            end = sec.end,
            ++answer;
        else
            end = min(end, sec.end);
    }

    return answer;
}
