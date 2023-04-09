#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K);

int main(int argc, char* argv[])
{
    cout << solution({1, 2, 3, 9, 10, 12}, 7) << endl;

    return 0;
}

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> prQue(scoville.begin(), scoville.end());

    while (prQue.top() < K)
    {
        if (prQue.size() == 1)
            return -1;

        int smallest = prQue.top(); prQue.pop();
        int second   = prQue.top(); prQue.pop();

        prQue.emplace(smallest + second + second);
        ++answer;
    }

    return answer;
}
