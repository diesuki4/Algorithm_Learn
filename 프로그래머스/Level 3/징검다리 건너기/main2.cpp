#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Stone;
int solution(vector<int> stones, int k);

int main(int argc, char* argv[])
{
    cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3) << endl;

    return 0;
}

struct Stone
{
    int idx;
    int step;

    friend bool operator < (const Stone& A, const Stone& B) { return A.step < B.step; }
};

int solution(vector<int> stones, int k)
{
    priority_queue<Stone> maxHeap;

    for (int i = 0; i < k; ++i)
        maxHeap.push(Stone {i, stones[i]});

    int answer = maxHeap.top().step;
    size_t n = stones.size();

    for (int i = k; i < n; ++i)
    {
        while (!maxHeap.empty() && maxHeap.top().idx <= i - k)
            maxHeap.pop();

        maxHeap.push(Stone {i, stones[i]});

        answer = min(answer, maxHeap.top().step);
    }

    return answer;
}
