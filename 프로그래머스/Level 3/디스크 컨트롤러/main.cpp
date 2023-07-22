#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

struct Job;
class compare;
int solution(vector<vector<int>> jobs);

int main(int argc, char* argv[])
{
    cout << solution({{0, 3}, {1, 9}, {2, 6}}) << endl;

    return 0;
}

struct Job
{
    int start;
    int duration;
};

class compare
{
public:
    bool operator()(const Job& A, const Job& B) { return A.duration > B.duration; }
};

int solution(vector<vector<int>> jobs)
{
    vector <int> answer;
    priority_queue<Job, vector<Job>, compare> minHeap;
    vector<Job> sortedJobs;
    int currentStart = 0, i = 0;

    for (auto& job : jobs)
        sortedJobs.emplace_back(Job{job[0], job[1]});

    sort(sortedJobs.begin(), sortedJobs.end(), [](Job& A, Job& B) { return A.start < B.start; });

    while (i < sortedJobs.size())
    {
        if (minHeap.empty())
            currentStart = max(currentStart, sortedJobs[i].start);

        while (i < sortedJobs.size() && sortedJobs[i].start <= currentStart)
            minHeap.emplace(Job{sortedJobs[i].start, sortedJobs[i].duration}),
            ++i;

        answer.emplace_back((currentStart += minHeap.top().duration) - minHeap.top().start);
        minHeap.pop();
    }

    while (!minHeap.empty())
    {
        answer.emplace_back((currentStart += minHeap.top().duration) - minHeap.top().start);
        minHeap.pop();
    }

    return accumulate(answer.begin(), answer.end(), 0) / answer.size();
}
