#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Section;
int solution(vector<vector<int>> routes);

int main(int argc, char* argv[])
{
    cout << solution({{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}}) << endl;

    return 0;
}

struct Section
{
    int start;
    int end;

    friend bool operator < (const Section& A, const Section& B) { return A.start > B.start; }
};

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    int end = -30'001;
    priority_queue<Section> prQue;

    for (vector<int>& rt : routes)
        prQue.push({rt[0], rt[1]});

    while (!prQue.empty())
    {
        Section sec = prQue.top(); prQue.pop();

        if (end < sec.start)
            end = sec.end,
            ++answer;
        else
            end = min(end, sec.end);
    }

    return answer;
}
